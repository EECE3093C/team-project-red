# Proposal For Our Software Project

## What is our project?

## Who is it for?

## What problem does it solve?

## What alternatives are available? Who are our competitors?

## What is the novel in our approach?

## Software Architecture / Language Plans?
The plan is to write our software in C++, as this is the language that the majority of the team is most familiar with.
The design will require the creation of various object classes to represent assignments, scheduled events, blocks of time to study, and so forth. The plan is to use the [Canvas API](https://canvas.instructure.com/doc/api/) to retrieve the user's assignment and schedule information from Canvas. There will also be an input/output area through the use of a command line interface, where the user can manually add events not reflected in the Canvas schedule.
Assignments will need to be organized into to-do lists for specific days, based on priority, due dates, and availability of time due to other scheduled events that day.

## Challenges and Risks?
