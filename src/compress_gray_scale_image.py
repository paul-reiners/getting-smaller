import matplotlib.pyplot as plt
import PIL
import numpy as np
from PIL import Image as im


def compress_gray_scale_image(input_file_path, output_file_path):
    an_image = PIL.Image.open(input_file_path)

    grayscale_image = an_image.convert("L")
    grayscale_array = np.asarray(grayscale_image)

    u, s, vh = np.linalg.svd(grayscale_array, full_matrices=True)
    print(u.shape, s.shape, vh.shape)

    ranks = [1, 5, 20, 50, 100]
    for rank in ranks:
        Xapprox = np.dot(u[:, :rank] * s[:rank], vh[:rank, :])

        data = im.fromarray(Xapprox)
        data = data.convert("L")

        data.save(output_file_path + "_rank_" + str(rank) + ".jpg")
