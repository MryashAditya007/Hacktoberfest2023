# How to use

This script will first connect to the database. It will then create a table to store the news and events, if it does not already exist.

Next, it will make a request to the Koenigsegg news and events URL and parse the RSS feed into a JSON object.

Finally, the script will iterate over the RSS feed items and insert them into the database.

It will also send an email to the email recipients with the latest Koenigsegg news and events.

To use the script, simply save it as a Python file (e.g. koenigsegg_news_and_email.py) and run it in a terminal:

```bash
python koenigsegg_news_and_email.py
```

The script will save the latest Koenigsegg news and events to the database and send an email to the email recipients.

That's all.
