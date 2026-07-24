## Arduino Projects

## Structure

Each project has its own `<project_name>` directory should have the following structure:
- `README.md`: high level overview of the project
- `WIRING.md`: wiring specifications
- `src/`: Contains the sketch file

## Files

Adhere to the standard structure for the followings:

### README.md

Required Sections:
- `Overview`
- `How it works`
- `Components`

### WIRING.md

Required Sections:
- `Components`: List of materials required (with count)
- `Connections`: Subsections for a component that is wired to the ardunio. Connection subsections must each have the following:
    - A table with the following columns (`Pin`, `Label` (if applicable), `Connects To`)
    - Notes on the specific connection (what voltage is required, hardware notes)
- `Pin Summary`


## Rules

Do the following when doing the following actions:

- **Update Wiring, Pin Assignments, or Adding a Component**: Update the `WIRING.md` file for the project