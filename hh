#predmeti = {1: 'astronomy', 2:'english',3:'bio',4:'vsemirka',5:'geography',6:'estestvo',7:'inf',8:'history',9:'iskustvo',10:'culture',11:'lit',12:'algebra',13:'geom',14:'mus',15:'math',16:'obzh',17:'obschestvo',18:'okrmir',19:'rus',20:'techno',21:'fizika',22:'himiya',23:'cherchenie',24:'ecology',25:'economy'}
#classy = int(input())
#predmet = int(input())
#print('http://uchebniki.net/',predmeti[predmet], classy, sep = '' )
import vk_api
from vk_api.longpoll import VkLongPoll, VkEventType
def write_msg(user_id, message):
    vk.method('messages.send', {'user_id': user_id, 'message': message , 'random_id': 0})
    
token = "87792e9dd7f24115c6425e19c241eac1fcb3f7f78f440a156941789f6a5367232eb18fbc4244e694de8b5"

# Авторизуемся как сообщество
vk = vk_api.VkApi(token=token)

# Работа с сообщениями
longpoll = VkLongPoll(vk)
# Основной цикл

for event in longpoll.listen():

    # Если пришло новое сообщение
    if event.type == VkEventType.MESSAGE_NEW:
        request = event.text
        print(request)
        # Если оно имеет метку для меня( то есть бота)
        if event.from_user and not (event.from_me):
            if request == "Физика 9":
                write_msg(event.user_id, "https://vk.com/doc234620348_535935357?hash=675f2a3580e007e5c8&dl=00f3507c3317c0d680")
                
            elif request == "Всеобщая история 11":
                write_msg(event.user_id, "https://vk.com/doc234620348_536362511?hash=47a06786a1daef3467&dl=109ffe5625ef901ca9")
                
            elif request == "Русский язык 10":
                write_msg(event.user_id, "https://vk.com/doc234620348_536362499?hash=96e04eee062dc60422&dl=47c5a1abe6f26c57ed")

            elif request == "Русский язык 11":
                write_msg(event.user_id, "https://vk.com/doc234620348_536362499?hash=96e04eee062dc60422&dl=47c5a1abe6f26c57ed")
                
            elif request == "Русский язык 10-11":
                write_msg(event.user_id, "https://vk.com/doc234620348_536362499?hash=96e04eee062dc60422&dl=47c5a1abe6f26c57ed")
                
            elif request == "Обществознание 10":
                write_msg(event.user_id, "https://vk.com/doc234620348_536362454?hash=30e8896c296cc4a660&dl=17067f442419eca81a")

            elif request == "Обществознание 11":
                write_msg(event.user_id, "https://vk.com/doc234620348_536362478?hash=75140de1bec2710db2&dl=49ccae9d0ac9c32263")
                
            else:
                write_msg(event.user_id, "Простите, данный предмет пока недоступен.")
