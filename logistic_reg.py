import numpy as np
import matplotlib.pyplot as plt

# Sample Data: Age vs Buy
X = np.array([20, 22, 25, 28, 30, 35])
y = np.array([0, 0, 0, 1, 1, 1])

# Normalize for stability (optional but helps)
X = (X - X.mean()) / X.std()

# Add bias term
X_b = np.c_[np.ones((len(X), 1)), X]

# Initialize weights (theta = [bias, weight])
theta = np.zeros(2)

# Sigmoid Function
def sigmoid(z):
    return 1 / (1 + np.exp(-z))

# Hyperparameters
learning_rate = 0.1
epochs = 1000
m = len(X)

# Gradient Descent
losses = []
for i in range(epochs):
    z = X_b.dot(theta)
    h = sigmoid(z)
    gradient = (1/m) * X_b.T.dot(h - y)
    theta -= learning_rate * gradient

    # Optional: track loss
    loss = -np.mean(y*np.log(h + 1e-10) + (1 - y)*np.log(1 - h + 1e-10))
    losses.append(loss)

    if i % 100 == 0:
        print(f"Epoch {i}: Loss = {loss:.4f}, θ = {theta}")

# Final Parameters
print("\nFinal Coefficients:", theta)

# Prediction for new age = 27
x_new = (27 - X.mean()) / X.std()
z_new = np.dot([1, x_new], theta)
prob = sigmoid(z_new)
print(f"Predicted probability of buying at age 27: {prob:.2f}")

# Plotting the sigmoid curve
x_plot = np.linspace(X.min(), X.max(), 100)
x_plot_b = np.c_[np.ones((len(x_plot), 1)), x_plot]
y_plot = sigmoid(x_plot_b.dot(theta))

plt.scatter(X, y, color='blue', label='Data')
plt.plot(x_plot, y_plot, color='red', label='Sigmoid Fit')
plt.axhline(0.5, color='gray', linestyle='--', label='Decision Boundary')
plt.title("Logistic Regression from Scratch")
plt.xlabel("Normalized Age")
plt.ylabel("Probability of Buying")
plt.legend()
plt.grid(True)
plt.show()
