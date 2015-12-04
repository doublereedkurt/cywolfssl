from distutils.core import setup, Extension
from Cython.Build import cythonize
import os, os.path

DIR = os.path.dirname(os.path.abspath(__file__))
WOLFSSL_INCLUDE = os.path.join(DIR, "lib", "wolfssl-3.7.0", "wolfssl-3.7.0")

extension = Extension('wolfssl', sources=['cywolfssl/wolfssl.pyx'],
    include_dirs=[WOLFSSL_INCLUDE],
    extra_objects=[DIR + "/lib/wolfssl-3.7.0/wolfssl-3.7.0/src/.libs/libwolfssl.a"])

setup(
    name='cywolfssl',
    ext_modules=cythonize(extension)
    )
