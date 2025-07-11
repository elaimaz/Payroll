# Payroll
Exercise of the book  Agile Software Development, Principles, Patterns, and Practices by Robert C. Martin.  

---

## UML Diagram Sketch
![PayrollUMLDiagramSketch.drawio.svg](./docs/images/PayrollUMLDiagramSketch.drawio.svg)  

---

## Running with Docker

Build the Docker image:
```bash
docker build -t payroll .
```

Run the container:
```bash
docker run -it --rm -v $(pwd):/app payroll
```

Or, with Docker Compose:
```bash
docker compose run --rm -it payroll
```  

## Running Tests

in the build file run:  
```bash
ctest
```