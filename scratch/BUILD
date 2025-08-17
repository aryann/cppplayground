load("@rules_cc//cc:cc_binary.bzl", "cc_binary")
load("@rules_cc//cc:cc_library.bzl", "cc_library")
load("@rules_cc//cc:cc_test.bzl", "cc_test")

cc_library(
    name = "scratch",
    srcs = ["scratch.cc"],
    hdrs = ["scratch.h"],
    deps = [
        "@abseil-cpp//absl/container:flat_hash_map",
        "@abseil-cpp//absl/status:status",
        "@abseil-cpp//absl/status:statusor",
    ],
)

cc_test(
    name = "scratch_test",
    size = "small",
    srcs = ["scratch_test.cc"],
    deps = [
        ":scratch",
        "@abseil-cpp//absl/status:status",
        "@abseil-cpp//absl/status:status_matchers",
        "@googletest//:gtest",
        "@googletest//:gtest_main",
    ],
)

cc_binary(
    name = "scratch_main",
    srcs = ["scratch_main.cc"],
    deps = [
        ":scratch",
    ],
)
