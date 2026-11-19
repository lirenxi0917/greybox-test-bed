# greybox-test-bed

**Greybox Test Bed** — a lightweight, placeholder-art sandbox used to prototype game
mechanics, level geometry, navigation flow, and interaction logic *before* any art pass.
All space is built from primitive volumes (boxes, capsules, planes) so that layout,
spacing, pacing, and feel can be iterated quickly without investing in final assets.

## 1. Project Goal

- Validate whether a proposed room, route, or mechanic is fun and readable using
  cheap greybox geometry only.
- Provide a fast-feedback loop for movement, collision, triggers, cover placement,
  and player pacing.
- Produce a documented, reproducible test bed that can be handed off to the production
  project once a layout and design are approved.
- Keep final art, textures, and audio out of this repository; this bed is for
  **structure and feel**, not presentation.

## 2. Target Users & Scope

- Users: game designers, level designers, and mechanics prototypers.
- In scope: placeholder maps, movement/collision, trigger zones, interactable
  placeholders, tunable layout parameters, and a validation checklist.
- Out of scope: final visuals, polished animation, story content, asset pipeline,
  and multiplayer (deferred to production).

## 3. Overall Architecture

### 3.1 Directory layout

```
greybox-test-bed/
├── README.md                 # this document: goal, architecture, Milestone 1 spec
├── .gitignore                # ignore rules for build output, caches, secrets
├── src/
│   ├── core/                 # bootstrap, scene loading, config/parameter tables
│   ├── player/               # placeholder capsule, movement, collision state
│   ├── level/                # greybox rooms, walls, navigation volumes, spawns
│   ├── interaction/          # triggers, interactable placeholders, doors/levers
│   └── utils/                # shared helpers, debug draw, input mapping
└── docs/
    ├── milestone-1.md        # Milestone 1 requirements checklist (tracking)
    └── validation-checklist.md# flow / spacing / pacing review before art pass
```

### 3.2 System modules

| Module | Responsibility | Key inputs | Key outputs |
|---|---|---|---|
| `core` | Initialize runtime, load active greybox scene, expose tunable parameters | Scene name, config values | Running scene, parameter table |
| `player` | Placeholder player capsule, locomotion, collision, spawn/reset | Input, level geometry | Player transform, movement state |
| `level` | Build rooms/walls/navigation volumes from placeholder meshes | Layout parameter table | Collidable level, spawn points, trigger anchors |
| `interaction` | Trigger zones and interactable placeholders (door, lever, pickup stub) | Player overlap / input | Event hooks, state changes |
| `utils` | Debug visualization, input mapping, logging, shared math | Runtime state | Debug overlay, helper APIs |

### 3.3 Data flow

```
config/parameters ──▶ core ──▶ level (geometry + volumes)
                          ──▶ player (movement + collision)
player overlap/input ──▶ interaction ──▶ event hooks ──▶ level/player state
all state ──▶ debug overlay (utils) for inspection and tuning
```

### 3.4 Runtime / stack (to be pinned in first implementation commit)

- Runtime/engine: TBD — candidate engines evaluated in Milestone 1.
- Placeholder art: primitive meshes and flat-colored volumes only.
- Code runtime: treated as generic; ignore rules below cover common Node/Python/build
  artifacts, with engine-specific rules to be added once the stack is chosen.

## 4. Milestone 1 — Requirements Document

**Milestone 1 objective:** A single loadable greybox scene with a controllable
placeholder player, basic collision, one navigable route, and at least one trigger
interactable, all wired to the validation checklist.

### 4.1 Must-have deliverables

1. **Bootstrapped scene**
   - Empty level loads on startup with a spawn point and a floor plane.
2. **Placeholder player**
   - Capsule actor that can move horizontally and collide with walls/obstacles.
   - Reset-to-spawn action available for repeated testing.
3. **Greybox geometry**
   - At least one enclosed room plus a connecting corridor built from boxes.
   - Clear navigation volumes; no gaps that let the player fall out of the test space.
4. **Collision & movement**
   - Player cannot pass through walls or leave the intended test area.
   - Movement speed and gravity (if applicable) exposed as tunable parameters.
5. **One trigger/interactable**
   - A zone or placeholder object that fires a visible/audible debug signal when the
     player enters or uses it (e.g., a door stub opening, a lever toggled).
6. **Debug tooling**
   - On-screen or overlay view of current position, speed, and active trigger state.
7. **Documentation**
   - This README (goal, architecture, Milestone 1 spec) and the validation
     checklist committed alongside the code.

### 4.2 Acceptance criteria

- The scene starts, the player can traverse the full route without soft-lock or
  falling out of bounds.
- At least one trigger reacts correctly to player overlap/input.
- All layout and movement values are adjustable without rewriting geometry by hand.
- A reviewer can open the repository, inspect the architecture, and reproduce the
  Milestone 1 scene from the committed code and docs.

### 4.3 Out of scope for Milestone 1

- Final art, textures, models, and polished animation.
- Multiple levels, save system, menus, audio, and multiplayer.
- Engine/asset pipeline optimization.

### 4.4 Milestone 1 tasks (initial tracking)

- [ ] Pin engine/runtime and record it in this README.
- [ ] Implement `core` bootstrap and scene loader.
- [ ] Implement `player` capsule with movement and collision.
- [ ] Build room + corridor greybox in `level`.
- [ ] Add one trigger/interactable in `interaction`.
- [ ] Add debug overlay in `utils`.
- [ ] Fill `docs/validation-checklist.md` and run the first layout review.

## 5. Roadmap (post Milestone 1)

1. Milestone 2: additional test rooms, cover placement, and route branching.
2. Milestone 3: mechanic tuning pass (combat/interaction placeholders, pacing metrics).
3. Milestone 4: freeze approved greybox layout and hand off to the production project.

## 6. Repository Conventions

- Commits describe the changed system and intent, not just "update code".
- Placeholder assets must remain primitive; do not commit production art here.
- Engine-specific ignore rules are added once the runtime is chosen in Milestone 1.

## 7. License

TBD on first production commit.
