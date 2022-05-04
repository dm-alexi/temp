VENV = venv
PYTHON = $(VENV)/bin/python3
PIP = $(VENV)/bin/pip

run: venv/bin/activate
	$(PYTNOH) wsgi.py

venv/bin/activate: requirements.txt
	python3 -m venv $(VENV)
	$(PIP) install --upgrage pip
	$(PIP) install -r requirements.txt

clean:
	rm -rf __pycache__
	rm -rf $(VENV)
