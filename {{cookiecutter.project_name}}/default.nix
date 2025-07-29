# You only need to use this file if you use nix to build your packages.
# If you don't, feel free to delete this.

{ lib
, pkg-config
, buildRosPackage
, ament-cmake
, ament-cmake-gtest
, ament-lint-auto
, gtest
, rclcpp
, pluginlib
, teleop-modular-control-mode
, rclcpp-lifecycle
}:

buildRosPackage {
  name = "{{cookiecutter.project_name | replace("_", "-")}}";
  buildType = "ament_cmake";

  src = builtins.path rec {
    name = "{{cookiecutter.project_name | replace("_", "-")}}-source";
    path = ./.;
  };

  nativeBuildInputs = [
    ament-cmake
    pkg-config
    ament-cmake-gtest
    ament-lint-auto
    gtest
  ];

  buildInputs = [
    rclcpp
    rclcpp-lifecycle
    pluginlib
    teleop-modular-control-mode
  ];

  propagatedBuildInputs = [
    # Add message packages here
  ];

  # Enable running tests during build?
  # doCheck = true;
}
