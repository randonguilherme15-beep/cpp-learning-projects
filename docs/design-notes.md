# C++ Design Notes

These are proposed development directions, not claims about features already present.

## Separate computation from interaction

A calculation function should receive values and return a result. Keep prompts, parsing, and formatting at the application boundary. For example, a travel-cost function can be checked with `days = 4` and `dailyCost = 25.0` independently of keyboard input; its expected total is `100.0`.

## Define state invariants

For a wallet, define whether negative balances are permitted before implementing purchases. For a garage, require a unique registration and a valid fuel category before changing occupancy. Check every precondition before committing a state transition.

## Make ownership explicit

Prefer `std::array<T, N>` for a fixed-size collection and `std::vector<T>` for a dynamic one. They express storage lifetime directly and avoid pairing manual allocation with cleanup. A dynamic-allocation exercise can still be retained to explain the underlying mechanism.

## Treat parsing as a boundary

Checking a numeric range does not handle a failed stream extraction. Read, validate, and reject malformed input explicitly. Ensure each menu has one documented exit condition and handles end-of-input without repeating indefinitely.

## Model money and persistence deliberately

Integer minor units can avoid binary floating-point rounding for simple monetary examples. Persistent data needs a defined format, validation on load, and error handling on save. A text file written successfully is not a database transaction or a concurrent booking system.

## Document measurable behaviour

For each change, state the trigger, expected result, and boundary cases. Example: reserving an available room changes exactly one occupancy entry; reserving it again should leave state unchanged. Build checks and behaviour checks provide different evidence and should be reported separately.
