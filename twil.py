from twilio.rest import TwilioRestClient


from imgurpython import ImgurClient

client_id = '3ddacdbd10e0d71'
client_secret = '85037f60c00294c91f55598b0b67a89ffc62a3a9'

client = ImgurClient(client_id, client_secret)

ret = client.upload_from_path("button.jpg", config=None, anon=True)

image_url = ret.get('link')



ACCOUNT_SID = "AC942cf3a4709c5898acd0b2f757ccdbeb" 
AUTH_TOKEN = "f37f9cd47a55ae8f2678376bc4106aed" 


 
client = TwilioRestClient(ACCOUNT_SID, AUTH_TOKEN)
 
message = client.messages.create(body="Selfie!",
    to="+14164369212", 
    from_="+16476910003", 
    media_url=image_url)
print message.sid