# Import requests (to download the page)
# import requests
#from urllib.request import urlopen, Request

# Import BeautifulSoup (to parse what we download)
#from bs4 import BeautifulSoup
# import bs4

# Import Time (to add a delay between the times the scape runs)
import time
print()
print()
print(time)
print()
print()

# Import smtplib (to allow us to email)
import smtplib
# This is a pretty simple script. The script downloads the homepage of VentureBeat, and if it finds some text, emails me.
# If it does not find some text, it waits 60 seconds and downloads the homepage again.

# while this is true (it is true by default),
while True:
    # set the url as VentureBeat,
    url = "https://hi.kattis.com/courses/TOL607G/vor2022"
    # set the headers like we are a browser,
    headers = {
        'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_10_1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/39.0.2171.95 Safari/537.36'}
    # download the homepage
    response = requests.get(url, headers=headers)
    # parse the downloaded homepage and grab all text, then,
    soup = bs4.BeautifulSoup(response.text, "lxml")

    # if the number of times the word "Vika" occurs on the page is 1,
    if str(soup).find("Vika") == 1:
        # wait 60 seconds,
        time.sleep(10)
        # continue with the script,
        continue

    # but if the word "Google" occurs any other number of times,
    else:
        # create an email message with just a subject line,
        msg = 'Subject: This is Ingimar\'s script talking, CHECK KATTIS!'
        # set the 'from' address,
        fromaddr = 'ilg5@hi.is'
        # set the 'to' addresses,
        toaddrs = ['ilg5@hi.is']

        # setup the email server,
        # server = smtplib.SMTP('smtp.gmail.com', 587)
        # server.starttls()
        # add my account login name and password,
        # server.login("YOUR_EMAIL_ADDRESS", "YOUR_PASSWORD")

        # Print the email's contents
        print('From: ' + fromaddr)
        print('To: ' + str(toaddrs))
        print('Message: ' + msg)

        # send the email
        # server.sendmail(fromaddr, toaddrs, msg)
        # disconnect from the server
        # server.quit()

        break
