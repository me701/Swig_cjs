
default: program

program:
	python setup.py build_ext
	python setup.py install --install-platlib=.
	python test.py
