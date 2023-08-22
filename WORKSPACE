# TensorFlow WORKSPACE file

# Load Bazel rules for TensorFlow
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# Fetch TensorFlow as an external dependency
http_archive(
    name = "org_tensorflow",
    urls = ["https://github.com/tensorflow/tensorflow/archive/refs/tags/v2.7.0.tar.gz"],
    strip_prefix = "tensorflow-2.7.0",
)

# Load TensorFlow dependencies and configurations
load("@org_tensorflow//tensorflow:tensorflow.bzl", "tf_workspace")

tf_workspace()