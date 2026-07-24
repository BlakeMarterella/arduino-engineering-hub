# Arduino Engineering Hub

Central repository for a variety of arduino projects. The root level contains general information about hardware and what I have. Specific projects get their own dedicated repository.

## Repo Structure

```
<repo root>/
    README.md
    hardware/
        - *.md (1 markdown per hardware component)
    projects/
        - <project_name>/README.md (project specific README)
```

## README.md

Needs to have the following sections:
- `Projects`: A table with the following columns
    - `Name` (link to the README of the project)
    - `Description` (1 sentence description)
    - `Created`
- `Hardware`: A table of the hardware I currently have with a link to its specifics

## Rules

### When introduced to a new component

Write a single markdown file (in the `hardware` directory) to document the high level overview of what it is, how to use it, relevant spec sheets. The documentation should not be specific to a certain project, keep it to general information