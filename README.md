# Proposal For Our Software Project

### What is our project? Who is it for?
Our product is a productivity application, similar to that of a planner, specifically designed for University of Cincinnati students. By taking in the users class assignments from Canvas, scheduled class times, and any other individual meetings or timed requirments, the application creates sample daily schedules and prioritizes a things to-do list based on the users unique needs. Along with this, suggestions for breaks or rest time and study or food locations near the University of Cincinnati are also created.
### What problem does it solve?
Our product solves a problem that many college students face- the difficulty of creating a schedule and staying organized. This product functions as a calendar, planner, and to-do list all in one. 
### What alternatives are available? Who are our competitors?
Some alternatives available are the built-in Calendar app on most cell phones, Microsoft Outlook, Google Calendar, ToDo, and the built in Canvas Calendar. 
### What is the novel in our approach?
Our product is different than the others that are already available because it not only includes a calendar, planner, and to-do list functionality, but also automatically generates daily schedules, rest times, and suggested food and study locations near the University of Cincinnati. The reason it is so relevant for college students is because our product gets class information and assignments directly from Canvas. Along with this, our approach is focused on University of Cincinnati students. 

### Software Architecture / Language Plans?
The plan is to write our software in C++, as this is the language that the majority of the team is most familiar with. <br>
The design will require the creation of various object classes to represent assignments, scheduled events, blocks of time to study, and so forth. The plan is to use the [Canvas API](https://canvas.instructure.com/doc/api/) to retrieve the user's assignment and schedule information from Canvas. The software will also pull coordinate locations from Google Maps to find study and food locations near where the student's classes take place. There will also be an input/output area through the use of a command line interface, where the user can manually add events not reflected in the Canvas schedule. <br>
Assignments will need to be organized into to-do lists for specific days, based on priority, due dates, and availability of time due to other scheduled events that day.

### Challenges and Risks?
This project will involve learning new skills and applying new tactics that many of us are not familiar with. We will need to learn how to use the Canvas API to the extent needed to utilize it in our app. We will also need to find a way of finding locations on Google Maps, and determining nearby study and food locations. This is tentatively the final step of development, and we may or may not be able to fully implement it. We will also need to build up familiarity with the different methodologies of the Agile Software Development process, and apply these effectively to stay on schedule. To help minimize these risks, we will attempt to start as small as possible when implementing new features, and work our way up.
