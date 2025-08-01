# {{cookiecutter.project_name}}/{{cookiecutter.control_mode_class_name}}

{{cookiecutter.description}}

### Inputs

#### Axes
*TODO: List and describe axes here*
- `speed`: The input axis that scales the output speed from 0 to 1.

#### Buttons
*TODO: List and describe buttons here*
- `locked`: When true, the control mode will send all zeroes to make the robot halt. *(optional)*

> **Note**: `locked` is automatically captured by teleop_modular and exposed through the `bool is_locked()` method.

### Parameters

*TODO: Describe your parameters here*

- `topic : string` The topic name to send messages to (Required)
- `qos : int` The ROS2 topic Quality of Service value to use in the publisher (Optional, defaults to 10) 

```yaml
# Example parameter file
teleop_node:
  ros__parameters:
    control_modes:
      names: [ "{{cookiecutter.project_name}}" ]
      twist_control_mode:
        type: "{{cookiecutter.project_name}}/{{cookiecutter.control_mode_class_name}}"

{{cookiecutter.project_name}}:
  ros__parameters:
    # Topic to send messages to (Required)
    topic: "/turtle1/cmd_vel"
    
    # The ROS2 topic Quality of Service value to use in the publisher (Optional, defaults to 10)
    qos: 10
    
    # TODO: Add an example usage of your parameters here
```
