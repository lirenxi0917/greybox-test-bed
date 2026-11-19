# Milestone 1 — Requirements Tracking

Objective: one loadable greybox scene with a controllable placeholder player, basic
collision, one navigable route, and one trigger interactable, wired to the validation
checklist.

## Requirement checklist

- [ ] Runtime/engine pinned and recorded in README.
- [ ] Bootstrap + scene loader (`core`).
- [ ] Placeholder capsule: movement, collision, reset to spawn (`player`).
- [ ] Greybox room + corridor, spawn point, navigation volumes (`level`).
- [ ] One trigger/interactable with debug feedback (`interaction`).
- [ ] Debug overlay: position, speed, active trigger state (`utils`).
- [ ] Validation checklist filled and first layout review run.

## Acceptance

- Full route traversable; player cannot leave bounds or soft-lock.
- Trigger reacts to overlap/input as designed.
- Layout and movement values tunable without hand-editing geometry.
- Reviewer can reproduce the Milestone 1 scene from committed code + docs.
