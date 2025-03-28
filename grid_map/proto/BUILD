package(default_visibility = ["//visibility:public"])

proto_library(
    name = "grid_map_proto",
    srcs = [
        "grid_map.proto",
        "grid_map_info.proto",
        "header.proto",
    ],
)

cc_proto_library(
    name = "grid_map_cc_proto",
    deps = [":grid_map_proto"],
)
