#include <tensorflow/cc/client/client_session.h>
#include <tensorflow/cc/ops/standard_ops.h>
#include <tensorflow/core/framework/tensor.h>

int main() {
    // Create a TensorFlow graph
    tensorflow::Scope root = tensorflow::Scope::NewRootScope();

    // Define some constants
    tensorflow::Output A = tensorflow::ops::Const(root.WithOpName("A"), { {3.f, 4.f}, {5.f, 6.f} });
    tensorflow::Output B = tensorflow::ops::Const(root.WithOpName("B"), { {7.f, 8.f}, {9.f, 10.f} });

    // Define a matrix multiplication operation
    tensorflow::Output matmul = tensorflow::ops::MatMul(root.WithOpName("MatMul"), A, B);

    // Create a TensorFlow session and run the computation
    tensorflow::ClientSession session(root);
    std::vector<tensorflow::Tensor> outputs;
    TF_CHECK_OK(session.Run({matmul}, &outputs));

    // Print the result
    std::cout << "Result: " << outputs[0].tensor<float, 2>() << std::endl;

    return 0;
}
