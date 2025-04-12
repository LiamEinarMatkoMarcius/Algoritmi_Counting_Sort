# Use a base image with Python and build tools
FROM python:3.11-slim

# Install C++ tools
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    && rm -rf /var/lib/apt/lists/*

# Set work directory
WORKDIR /app

# Copy everything to the container
COPY . .

# Optional: Compile C++ code (update based on how your project is structured)
RUN g++ -o my_app Counting_Roman_sort.cpp

# Install Python dependencies
RUN pip install --upgrade pip && \
    pip install -r requirements.txt

# Default command runs tests (adjust if needed)
CMD ["pytest", "tests/"]
