load("@rules_cc//cc:cc_binary.bzl", "cc_binary")
load("@rules_cc//cc:cc_library.bzl", "cc_library")
load("@rules_cc//cc:cc_test.bzl", "cc_test")

cc_library(
    name = "queue",
    srcs = [
    ],
    hdrs = ["queue.h"],
    deps = [
        "@abseil-cpp//absl/container:flat_hash_map",
    ],
)

cc_test(
    name = "queue_test",
    size = "small",
    srcs = ["queue_test.cc"],
    deps = [
        ":queue",
        "@googletest//:gtest",
        "@googletest//:gtest_main",
    ],
)

cc_binary(
    name = "queue_main",
    srcs = ["queue_main.cc"],
    deps = [
        ":queue",
    ],
)
