import requests
from bs4 import BeautifulSoup

# URL of the website you want to scrape
url = 'https://example.com'

# Send a GET request to the URL
response = requests.get(url)

# Parse the HTML content of the webpage
soup = BeautifulSoup(response.text, 'html.parser')

# Find specific elements from the webpage
# Example: finding all the links on the webpage
links = soup.find_all('a')

# Print the links
for link in links:
    print(link.get('href'))

# Example: finding all the paragraph texts on the webpage
paragraphs = soup.find_all('p')

# Print the paragraphs
for paragraph in paragraphs:
    print(paragraph.get_text())
