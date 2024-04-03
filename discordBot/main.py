# IMPORT DISCORD.PY. ALLOWS ACCESS TO DISCORD'S API.
import discord
from discord.ext import commands
from discord import app_commands
# IMPORT THE OS MODULE.
from io import BytesIO
import os
import random
import asyncio
import urllib.request
from PIL import Image
import pytesseract
import cv2
import numpy
from datetime import datetime
import yt_dlp as youtube_dl

# IMPORT LOAD_DOTENV FUNCTION FROM DOTENV MODULE.
from dotenv import load_dotenv

# LOADS THE .ENV FILE THAT RESIDES ON THE SAME LEVEL AS THE SCRIPT.
load_dotenv("bot.env")

# GRAB THE API TOKEN FROM THE .ENV FILE.
DISCORD_TOKEN = os.getenv("DISCORD_TOKEN")

path_to_tesseract = r'D:\Tesseract-OCR\tesseract.exe'

pytesseract.tesseract_cmd = path_to_tesseract


# GETS THE CLIENT OBJECT FROM DISCORD.PY. CLIENT IS SYNONYMOUS WITH BOT.
intents = discord.Intents.all()
#client = discord.Client(intents=intents)
bot = commands.Bot(command_prefix='!', intents=intents)
#bot = app.CommandTree(client)


youtube_dl.utils.bug_reports_message = lambda: ''
ytdl_format_options = {
    'format': 'bestaudio/best',
    'restrictfilenames': True,
    'noplaylist': True,
    'nocheckcertificate': True,
    'ignoreerrors': False,
    'logtostderr': False,
    'quiet': True,
    'no_warnings': True,
    'default_search': 'auto',
    'source_address': '0.0.0.0' # bind to ipv4 since ipv6 addresses cause issues sometimes
}
ffmpeg_options = {
	'options': '-vn',
	"before_options": "-reconnect 1 -reconnect_streamed 1 -reconnect_delay_max 5"
}
ytdl = youtube_dl.YoutubeDL(ytdl_format_options)



    


# EVENT LISTENER FOR WHEN THE BOT HAS SWITCHED FROM OFFLINE TO ONLINE.
@bot.event
async def on_ready():
	await bot.change_presence(status=discord.Status.dnd,activity = discord.Activity(name = "Cool Games", type = 5))
	print('We have logged in as {0.user}'.format(bot))
			
@bot.tree.command(name = "test")
async def test(ctx: discord.Interaction, arg: str):
	await ctx.response.send_message(arg)

@bot.tree.command(name = "helper")
async def helper(ctx: discord.Interaction):
	await ctx.response.send_message("Help:\nJoin: Joins user's voice channel\n Leave: Leaves user's voice channel\nTime: current time\nPicture: random picture\nHello: hello response\nKakul: Hell Kakul Guide\nRollDice: rolls 6 sided die\nMute: mutes targeted user\n Deafen: deafens targeted user\n")

@bot.command()
async def join(ctx):
	if(ctx.author.voice != None):
		await ctx.channel.send("joining")
		channel = ctx.author.voice.channel
		await channel.connect()
		await ctx.guild.change_voice_state(channel = channel, self_deaf = False, self_mute = False)
	else:
		await ctx.channel.send("not joining")

@bot.command()
async def leave(ctx):
	channel = ctx.guild.voice_client
	await channel.disconnect()


@bot.command()
async def time(ctx):
	now = datetime.now()
	current_time = now.strftime("%H:%M:%S")
	await ctx.channel.send(current_time)

@bot.command()
async def picture(ctx):
	await ctx.channel.send(file = discord.File("pic1.png"))

@bot.command()
async def hello(ctx):
	await ctx.channel.send("what up dirtbag :sunglasses:")

@bot.command()
async def kakul(ctx):
	await ctx.channel.send("https://docs.google.com/document/d/1AlVGlk78A1fUxey2CMDP1BnHlxfBMm0jK6QoSgtNFik/edit")

@bot.command()
async def RollDice(ctx):
	x = random.randint(1,6)
	await ctx.channel.send("Rolling Dice\nD: " + str(x))

@bot.tree.command(name = "status")
async def status(ctx: discord.Interaction, member: discord.Member):
	await ctx.response.send_message(getStatus(member))

@bot.tree.command(name = "mute")
async def mute(ctx: discord.Interaction, member: discord.Member):
	#if ctx.message.author.guild_permissions.administrator:
	#	if not checkVoice(member):
	#		await ctx.channel.send("Muting " + member.display_name)
	#		await member.edit(mute = True)
	#	else:
	#		await ctx.channel.send(member.display_name + " is already Muted ....\nUnmuting")
	#		await member.edit(mute = False)
	#else:
	#	await ctx.channel.send("Cannot change voice status without permission")
	if ctx.user.guild_permissions.administrator:
		if not checkVoice(member):
			await ctx.response.send_message("Muting " + member.display_name)
			await member.edit(mute = True)
		else:
			await ctx.response.send_message(member.display_name + " is already Muted ....\nUnmuting")
			await member.edit(mute = False)
	else:
		await ctx.response.send_message("Cannot change voice status without permission")

@bot.tree.command(name = "deafen")
async def deafen(ctx: discord.Interaction, member: discord.Member):
	if ctx.user.guild_permissions.administrator:
		if not checkDeaf(member):
			await ctx.response.send_message("Deafening " + member.display_name)
			await member.edit(deafen = True)
		else:
			await ctx.response.send_message(member.display_name + " is already Deafened ....\nUndeafening")
			await member.edit(deafen = False)
	else:
		await ctx.response.send_message("Cannot change voice status without permission")

@bot.command()
async def play(ctx,url):
	if(ctx.author.voice != None):
		songQueue = []
		songQueue.append(url)
		if not listEmpty(songQueue):
			url = songQueue[0]
			songQueue.pop()
			with youtube_dl.YoutubeDL(ytdl_format_options) as ydl:
   				song_info = ydl.extract_info(url, download=False)
			if not ctx.voice_client.is_playing():
				await ctx.voice_client.play(discord.FFmpegPCMAudio(song_info["url"], **ffmpeg_options)) 
	else:
		await ctx.channel.send("Not connected to VC")

@bot.command()
async def setTimer(ctx,time: str):
	time = int(time)
	if (time < 0):
		await ctx.channel.send("Not valid")
	else:
		await ctx.channel.send("Timer set for " + str(time) + " minutes")
		time *= 60
		await asyncio.sleep(time)
		await ctx.author.send("Time's up!")

@bot.command()
async def sync(ctx):
	await ctx.channel.send("Syncing")
	await bot.tree.sync()

@bot.command()
async def getFS(ctx):
	if ctx.message.attachments:
		image_bytes = await ctx.message.attachments[0].read()
		img = Image.open(BytesIO(image_bytes))
		cvImg = numpy.array(img)
		cvImg = cv2.cvtColor(cvImg, cv2.COLOR_RGB2BGR)
		
		hsv = cv2.cvtColor(cvImg, cv2.COLOR_BGR2HSV)
		lower_green = numpy.array([35,100,100])
		upper_green = numpy.array([75,255,255])
		maskImg = cv2.inRange(hsv, lower_green, upper_green)
		result = cv2.bitwise_and(cvImg, cvImg, mask = maskImg)
		result = cv2.resize(result, None, fx=1.5, fy=1.5, interpolation=cv2.INTER_CUBIC)
		#cv2.imshow('original', hsv)
		#cv2.imshow('mask', maskImg)
		#cv2.imshow('result', result)
		cv2.waitKey(0)


		filename = "{}.jpg".format(os.getpid())
		cv2.imwrite(filename, result)
		
		#text = pytesseract.image_to_string(result)
		text = pytesseract.image_to_string(Image.open(filename), lang='eng', config='--psm 11')
		splitString = list(text.split("\n"))
		mainStat = 0
		allStat = 0
		for s in splitString:
			print(s + "\n")
			if '+' in s:
				if '%' in s:
					allStat = int(s[1])
					break
				else:
					cleanString = s.strip("+ |")
					#print(cleanString)
					mainStat = max(mainStat, int(cleanString))
		os.remove(filename)
		flameScore = calculateFS(allStat, mainStat)
		await ctx.channel.send("Calculating Flame Score\nFlame Score: " + str(flameScore) + "\n" + str(mainStat) + " " + str(allStat) + "\n")
	else:
		await ctx.channel.send("No image to process")

@bot.command()
async def status2(ctx):
	await ctx.channel.send(getStatus(ctx.author))

def checkVoice(member: discord.Member):
	return member.voice.mute

def checkDeaf(member: discord.Member):
	return member.voice.deaf

def getStatus(member: discord.Member):
	return member.status

def listEmpty(L):
	return L == []

def calculateFS(allStat: int, mainStat: int):
	return 8*allStat + mainStat

# EXECUTES THE BOT WITH THE SPECIFIED TOKEN. TOKEN HAS BEEN REMOVED AND USED JUST AS AN EXAMPLE.
bot.run(DISCORD_TOKEN)