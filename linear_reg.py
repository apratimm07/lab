import numpy as np
import matplotlib.pyplot as plt

# Sample Data
X = np.array([1, 2, 3, 4, 5])
y = np.array([2, 4, 6, 8, 10])  # y = 2x (perfect linear relationship)

# Add bias term (intercept)
X_b = np.c_[np.ones((len(X), 1)), X]  # Shape: (m, 2) => [[1, x1], [1, x2], ...]

# Initialize weights (theta = [bias, weight])
theta = np.zeros(2)

# Hyperparameters
learning_rate = 0.01
epochs = 1000

m = len(X)
# Gradient Descent
for epoch in range(epochs):
    predictions = X_b.dot(theta)              # ŷ = X * theta
    errors = predictions - y                  # residuals
    gradients = 2/m * X_b.T.dot(errors)       # ∂MSE/∂θ
    theta -= learning_rate * gradients        # update step

# Final parameters
print("Final weights (theta):", theta)

# Predict value for x = 6
x_predict = 6
y_predict = theta[0] + theta[1] * x_predict
print(f"Prediction for x = {x_predict}:", y_predict)

# Plotting the results
plt.scatter(X, y, color='blue', label='Training data')
plt.plot(X, X_b.dot(theta), color='red', label='Learned line')
plt.scatter([x_predict], [y_predict], color='green', marker='x', s=100, label=f'Prediction (x={x_predict})')
plt.title("Linear Regression using Gradient Descent")
plt.xlabel("X")
plt.ylabel("y")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.show()
