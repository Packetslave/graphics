cc_library(
  name = "canvas",
  srcs = [
    "Canvas.h",
  ]
)

cc_library(
  name = "color",
  srcs = [
    "Color.h",
  ]
)

cc_library(
    name = "timer",
    srcs = [
        "Timer.h"
    ]
)

cc_library(
  name = "tuple",
  srcs = [
    "Tuple.h",
  ]
)

cc_library(
  name = "point",
  srcs = [
    "Point.h",
  ],
  deps = [
    ":tuple",
    ":vector3",
  ]
)

cc_library(
  name = "vector3",
  srcs = [
    "Vector3.h",
  ],
  deps = [
    ":tuple",
  ]
)

cc_library(
  name = "intersection",
  srcs = [
    "Intersection.h",
  ]
)

cc_library(
  name = "ray",
  srcs = [
    "Ray.h",
  ],
  deps = [
    ":point",
    ":vector3",
  ]
)

cc_library(
  name = "sphere",
  srcs = [
    "Sphere.h",
  ],
  deps = [
    ":intersection",
    ":ray",
  ]
)

cc_binary(
  name = "sphere_test1",
  srcs = [
    "sphere_test1.cpp",
  ],
  deps = [
    ":canvas",
    ":color",
    ":sphere",
    ":timer",
    "@com_google_absl//absl/strings:str_format",
  ]
)

