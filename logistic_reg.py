import numpy as np

# Sample Binary Classification Data
X = np.array([[1], [2], [3], [4], [5]])
y = np.array([0, 0, 0, 1, 1])  # 0 for small values, 1 for large

# Add bias term
X_b = np.c_[np.ones((len(X), 1)), X]  # shape: (m, 2)

# Initialize weights
theta = np.zeros(2)

# Sigmoid function
def sigmoid(z):
    return 1 / (1 + np.exp(-z))

# Hyperparameters
lr = 0.1
epochs = 1000

# Gradient Descent
for _ in range(epochs):
    z = X_b.dot(theta)
    h = sigmoid(z)
    gradients = X_b.T.dot(h - y) / len(X)
    theta -= lr * gradients

print("Final weights:", theta)
print("Prediction for x = 6:", sigmoid(theta[0] + theta[1] * 6))