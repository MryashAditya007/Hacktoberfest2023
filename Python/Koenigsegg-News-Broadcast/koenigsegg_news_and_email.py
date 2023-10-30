# The script will save the latest Koenigsegg news and events to the database and send an email to the email recipients.
# Import necessary libraries
import requests
import json
import smtplib

# Define the Koenigsegg news and events URL
KOENIGSEGG_NEWS_URL = "https://www.koenigsegg.com/news/rss/"

# Define the database connection parameters
DATABASE_HOST = "localhost"
DATABASE_PORT = 3306
DATABASE_USER = "root"
DATABASE_PASSWORD = "password"
DATABASE_NAME = "koenigsegg_news"

# Define the email sender and recipient addresses
EMAIL_SENDER = "my@email.com"
EMAIL_RECIPIENTS = ["recipient1@email.com", "recipient2@email.com"]

# Connect to the database
database = pymysql.connect(host=DATABASE_HOST, port=DATABASE_PORT, user=DATABASE_USER, password=DATABASE_PASSWORD, database=DATABASE_NAME)

# Create a cursor object
cursor = database.cursor()

# Create a table to store the news and events
cursor.execute("""CREATE TABLE IF NOT EXISTS news (
    id INT NOT NULL AUTO_INCREMENT,
    title VARCHAR(255) NOT NULL,
    link VARCHAR(255) NOT NULL,
    created_at DATETIME NOT NULL,
    PRIMARY KEY (id)
)""")

# Make a request to the Koenigsegg news and events URL
response = requests.get(KOENIGSEGG_NEWS_URL)

# Parse the RSS feed into a JSON object
rss_feed = json.loads(response.content)

# Iterate over the RSS feed items
for item in rss_feed["items"]:

    # Insert the news and event into the database
    cursor.execute("""INSERT INTO news (title, link, created_at) VALUES (%s, %s, %s)""", (item["title"], item["link"], datetime.datetime.now()))

    # Commit the changes to the database
    database.commit()

# Send the news and events to the email recipients
for email_recipient in EMAIL_RECIPIENTS:

    # Create an email message
    email_message = """Subject: Latest Koenigsegg News and Events

    Here are the latest Koenigsegg news and events:

    """

    # Get the news and events from the database
    cursor.execute("SELECT title, link FROM news ORDER BY created_at DESC")

    # Iterate over the news and events and add them to the email message
    for news_event in cursor:
        email_message += f"- {news_event[0]} ({news_event[1]})\n"

    # Send the email message
    smtp_server = smtplib.SMTP("localhost", 587)
    smtp_server.starttls()
    smtp_server.login(EMAIL_SENDER, "password")
    smtp_server.sendmail(EMAIL_SENDER, email_recipient, email_message)
    smtp_server.quit()

# Close the database connection
database.close()
