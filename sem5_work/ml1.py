import math
import numpy as np

def cosine_similarity_manual(a, b):
    dot = sum(x * y for x, y in zip(a, b))

    mag_a = math.sqrt(sum(x * x for x in a))
    mag_b = math.sqrt(sum(x * x for x in b))

    return dot / (mag_a * mag_b)


def cosine_similarity_numpy(a, b):
    a, b = np.array(a), np.array(b)
    return np.dot(a, b) / (np.linalg.norm(a) * np.linalg.norm(b))

vector1 = [1, 2, 3]
vector2 = [2, 4, 6]
vector3 = [1, 0, -1]

print(f"Manual:  {cosine_similarity_manual(vector1, vector2):.3f}")
print(f"NumPy:   {cosine_similarity_numpy(vector1, vector2):.3f}")

print(f"Manual:  {cosine_similarity_manual(vector1, vector3):.3f}")
print(f"NumPy:   {cosine_similarity_numpy(vector1, vector3):.3f}")