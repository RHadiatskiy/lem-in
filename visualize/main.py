import sys, pygame
from pygame.locals import *

rooms = []
links = []
ants = []
start_room = ''
end_room = ''


def get_max(rooms, index):
	m = int(rooms[0][index])

	for i, x in enumerate(rooms):
		if int(rooms[i][index]) > m:
			m = int(rooms[i][index])
	return m


def get_min(rooms, index):
	m = int(rooms[0][index])

	for i, y in enumerate(rooms):
		if int(rooms[i][index]) < m:
			m = int(rooms[i][index])
	return m


def paint_map(rooms):
	pygame.init()

	(window_width, window_height, window_title) = (900, 600, 'Lem-In')
	screen = pygame.display.set_mode((window_width, window_height), 0, 32)
	pygame.display.set_caption(window_title)
	bgColor = (255, 255, 255)
	figureSize = 50

	mainLoop = True

	max_x = get_max(rooms, 1)
	max_y = get_max(rooms, 2)

	coof_x = (window_width - (figureSize * 2)) / int(max_x) if int(max_x) > 0 else 1
	coof_y = (window_height - (figureSize * 2)) / int(max_y) if int(max_y) > 0 else 1

	while mainLoop:
		for event in pygame.event.get():
			if event.type == pygame.QUIT:
				mainLoop = False
		screen.fill(bgColor)
		for room in rooms:
			x = int(room[1]) * coof_x
			y = int(room[2]) * coof_y
			pygame.draw.rect(screen, (255, 0, 255), ((x, y), (figureSize, figureSize)), 0)
			# pygame.draw.circle(screen, (0, 0, 255), (x, y), figureSize, 0)
		pygame.display.update()

	pygame.quit()


def parse(line):
	if line.rstrip().isdigit():
		ants.append(int(line.strip()))
	elif line.startswith('#'):
		pass
		# print 'comment\n', line
	elif line.startswith('L'):
		pass
		# print 'visualize\n'
	else:
		line = line.split()
		if len(line) == 3:
			rooms.append(line)
		elif len(line) == 1:
			links.append(line)


with open('visualize/lem-in.txt', 'w+') as data:
	data.write(sys.stdin.read())

with open('visualize/lem-in.txt') as data:
	start = False
	end = False
	for line in data.readlines():
		if line == 'ERROR\n':
			print('ERROR')
			break
		elif start == True:
			start_room = line[:]
			start = False
			parse(line)
		elif end == True:
			end_room = line[:]
			end = False
			parse(line)
		elif line == '##start\n': start = True
		elif line == '##end\n': end = True
		else:
			parse(line)
	else:
		paint_map(rooms)



print 'ANTS:'
print ants

print 'ROOMS:'
for room in rooms:
	print room

print "LINKS:"
for link in links:
	print link

print "START ROOM:"
print start_room

print "END ROOM:"
print end_room