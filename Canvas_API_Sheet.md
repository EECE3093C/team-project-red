# Canvas API Sheet
## What is an API?
API stands for Application Programming Interface, which is a set of protocols, routines, and tools used for building software applications. In general, an API defines how different software components should interact with each other. In the context of web applications, an API is a set of endpoints that can be accessed over the internet to retrieve or manipulate data.
## Canvas LMS REST API High Level Overview
Canvas is a learning management system (LMS) that provides an [API](https://canvas.instructure.com/doc/api/) for developers to access and manipulate course data, users, assignments, and other features. To use the Canvas API to retrieve data from Canvas, you will need to follow these steps:
1. Obtain an API access token: You will need an access token to authenticate and authorize your requests to the Canvas API. To obtain an access token, you need to be an authorized user in Canvas and generate an access token from your Canvas account. The access token is a string of characters that you will need to use in your API requests to authenticate them.
2. Choose an API endpoint: Canvas provides a wide range of API endpoints that allow you to access different types of data. You will need to choose the appropriate endpoint that contains the data you need. The API documentation for Canvas provides a list of endpoints, along with their parameters and responses.
3. Construct an API request: Once you have chosen the appropriate endpoint, you can construct an API request by specifying the necessary parameters and passing the access token in the request header. The request URL will contain the endpoint and any additional parameters required to retrieve the desired data.
4. Send the API request: Once you have constructed the API request, you can send it using an HTTP client library such as Python's requests library or through a tool such as Postman. The response from the API will contain the data you requested in the specified format, such as JSON or XML.
## How to access the Canvas API
Obtain an access token: You can generate an access token by following these steps:
1. Log in to your Canvas account as an administrator or a teacher.
2. Go to "Account" and select "Settings".
3. Click on the "New Access Token" button to generate a new access token.
4. Give your access token a name and select the desired permissions.
5. Click on the "Generate Token" button to create your access token.

### Example of how to extract assignments and due dates using the Canvas LMS REST API
```python
import requests

# Set up the API endpoint and parameters
base_url = "https://canvas.instructure.com/api/v1"
course_id = "12345"
assignments_url = f"{base_url}/courses/{course_id}/assignments"
calendar_events_url = f"{base_url}/users/self/calendar_events"
params = {"start_date": "2022-02-01", "end_date": "2022-02-28"}

# Set up the API request headers with your access token
headers = {"Authorization": "Bearer YOUR_ACCESS_TOKEN"}

# Send the API request to extract assignment due dates
response = requests.get(assignments_url, headers=headers)
assignments = response.json()
for assignment in assignments:
    title = assignment["name"]
    due_date = assignment["due_at"]
    print(f"{title}: due on {due_date}")

# Send the API request to extract test information
response = requests.get(calendar_events_url, headers=headers, params=params)
calendar_events = response.json()
for event in calendar_events:
    if "Test" in event["title"]:
        title = event["title"]
        start_time = event["start_at"]
        print(f"{title}: starts at {start_time}")

# Send the API request to extract course schedule
response = requests.get(calendar_events_url, headers=headers, params=params)
calendar_events = response.json()
for event in calendar_events:
    if "Lecture" in event["title"]:
        title = event["title"]
        start_time = event["start_at"]
        end_time = event["end_at"]
        print(f"{title}: {start_time} to {end_time}")
```
## Go to this [link](https://github.com/ubc/getting-started-with-the-canvas-api-with-python)
