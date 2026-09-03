# ex03 — Unnecessary violence — eval notes

## What this exercise demonstrates
Reference vs pointer as class members, used to model two different
ownership/lifetime relationships to the same `Weapon`.

## Design
- `Weapon`: holds `type` (std::string). `getType()` returns `const std::string&`
  (no copy). `setType()` mutates it. HumanA/B never own a Weapon — they just
  refer to one that lives in `main`, so there's no `new`/`delete` and nothing
  to leak (verified with `leaks --atExit`, 0 leaks).

- `HumanA` stores `Weapon& weapon` (reference).
  - Why a reference: HumanA always has a weapon, and it's given to them once,
    when they're created. A reference has to be given its object right away
    (you can't create one first and assign it later), and once set, it can
    never be switched to point at a different object. That fits "always has
    exactly one weapon" exactly. Bonus: a reference can never be null, so
    there's no risk of an unarmed HumanA.

- `HumanB` stores `Weapon* weapon` (pointer), initialized to `NULL` in the
  constructor, set later via `setWeapon(Weapon&)`.
  - Why a pointer: HumanB may have *no* weapon at first (needs a "null"
    state, which a reference can't represent) and gets armed *later*, i.e.
    the member needs to be reassignable after construction — both things
    only a pointer allows.

- Both `attack()` print `<name> attacks with their <weapon type>` by calling
  `weapon.getType()` (HumanA) or `weapon->getType()` (HumanB, guarded by a
  null check first).

## Things to say if asked in the eval
- "When would you use a pointer to Weapon, and when a reference?"
  → Reference when the relationship is mandatory and fixed for the object's
  lifetime (HumanA: always armed, weapon set once). Pointer when the
  relationship is optional and/or can change after construction (HumanB: may
  have no weapon, can be armed later).
- Neither Human class owns its Weapon (no `new` inside HumanA/HumanB), so
  there's no destructor cleanup needed and no leak — the Weapon in `main`
  outlives both.
- Known nitpick: `Weapon::getType()` isn't marked `const`, so it can't be
  called on a `const Weapon&`. Works here because it's never called through a
  const reference, but a stricter eval might flag it.
