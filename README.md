# Proposal For Our Software Project

## What is our project?

## Who is it for?

## What problem does it solve?

## What alternatives are available? Who are our competitors?

## What is the novel in our approach?

## Software Architecture / Language Plans?
The plan is to write our software in C++, as this is the language that the majority of the team is most familiar with. <br>
The design will require the creation of various object classes to represent assignments, scheduled events, blocks of time to study, and so forth. The plan is to use the [Canvas API](https://canvas.instructure.com/doc/api/) to retrieve the user's assignment and schedule information from Canvas. The software will also pull coordinate locations from Google Maps to find study and food locations near where the student's classes take place. There will also be an input/output area through the use of a command line interface, where the user can manually add events not reflected in the Canvas schedule. <br>
Assignments will need to be organized into to-do lists for specific days, based on priority, due dates, and availability of time due to other scheduled events that day.

## Challenges and Risks?
This project will involve learning new skills and applying new tactics that many of us are not familiar with. We will need to learn how to use the Canvas API to the extent needed to utilize it in our app. We will also need to find a way of finding locations on Google Maps, and determining nearby study and food locations. This is tentatively the final step of development, and we may or may not be able to fully implement it. We will also need to build up familiarity with the different methodologies of the Agile Software Development process, and apply these effectively to stay on schedule. To help minimize these risks, we will attempt to start as small as possible when implementing new features, and work our way up.