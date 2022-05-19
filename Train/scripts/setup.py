import os
import sys
import glob
import json
import matplotlib.pyplot as plt
import math
import numpy as np
import PIL
from pathlib import Path
import shutil
import tensorflow as tf
from tensorflow import keras
from tensorflow.keras.utils import image_dataset_from_directory
from keras import layers
from IPython.display import Image, display

DATASET_FILENAME     = "deep_pen_dataset"
SAVED_MODEL_FILENAME = "saved_model"
FMODEL_FILENAME      = "float_model.tfl"
QMODEL_FILENAME      = "quantized_model.tfl"
MODEL_FILENAME       = "deep_pen_model_data.cc"

os.system(" apt-get -qq update && apt-get -qq install xxd ")

os.system(" wget 'https://drive.google.com/uc?export=download&id=1NBUAHjxW3ROO3EUmQORnxDMvTSJbj-R6' -O {DATASET_FILENAME}.tar.gz -q ")
os.system(" rm -rf {DATASET_FILENAME} ")
os.system(" tar xvzf {DATASET_FILENAME}.tar.gz 1>/dev/null ")
os.system(" rm -rf {DATASET_FILENAME}.tar.gz sample_data ")
os.system(" mkdir -p checkpoints ")


print("OK") if os.path.exists(DATASET_FILENAME) else print("Error")