# line-following-bot

# What is this?
This is a simple line following robot, made as the culminating project for Robotics for Sustainable Economic Growth around the World CREATE course hosted by the University of Toronto.
It uses three IR sensors to pathfind, and uses one hypersonic sensor to achieve basic object detection. 

# How to use the code
- make sure your pin connections are set to the right sockets
- fine tune speeds based off both motor quality and weight being carried. The current speeds were tuned with 500g added weight in mind

# What can it do?
- can support up to 500g while still achieving under 20 second lap times (heavier weights have not been tested)
- Basic object detection. It's hardcoded to go around one side. There is code in thhis repository for theoretically more advanced object detection, which would involve a servo


### Other Stuff
- Allegedly the fastest bot throughout all weeks
- Went through about 7 IR sensors before we found a working one
- POWER GUZZLER (will use up a 9V battery essentially per run)
