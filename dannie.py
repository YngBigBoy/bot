from vk_api.longpoll import VkLongPoll, VkEventType
import vk_api
import apiai, json
from datetime import datetime

login, password = "89855298639", "qantum11"
vk_session = vk_api.VkApi(login=login, password=password, app_id=2685278)
vk_session.auth(token_only=True)




session_api = vk_session.get_api()
longpoll = VkLongPoll(vk_session)

for event in longpoll.listen():
    if event.type == VkEventType.MESSAGE_NEW:
        print('time: ' + str(datetime.strftime(datetime.now(), "%H:%M:%S")))
        print('message: ' + str(event.text))
        print(event.user_id)
        response = event.text.lower()
        if event.from_user and not (event.from_me):
            if response:
                request = apiai.ApiAI('5c38469c3f3a492aaaf6660577ad6088').text_request()
                request.lang = 'ru'
                request.session_id = '3301megabot'
                request.query = response
                responseJson = json.loads(request.getresponse().read().decode('utf-8'))
                response=''
                response1 = responseJson['result']['fulfillment']['speech']
                if response1:
                    vk_session.method('messages.send',
                                    {'user_id': event.user_id, 'message': response1 , 'random_id': 0})
                else:
                    vk_session.method('messages.send',
                                {'user_id': event.user_id, 'message': 'Я Вас не совсем понял!', 'random_id': 0})
