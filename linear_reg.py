import numpy as np

# Sample Data
X = np.array([1, 2, 3, 4, 5])
y = np.array([2, 4, 6, 8, 10])  # Perfect linear relation (y = 2x)

# Add bias term
X_b = np.c_[np.ones((len(X), 1)), X]  # shape: (m, 2)

# Initialize weights
theta = np.zeros(2)  # [bias, weight]

# Hyperparameters
lr = 0.01
epochs = 1000

# Gradient Descent
for _ in range(epochs):
    gradients = 2 / len(X) * X_b.T.dot(X_b.dot(theta) - y)
    theta -= lr * gradients

print("Final weights:", theta)
print("Prediction for x = 6:", theta[0] + theta[1] * 6)
