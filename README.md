# Развертка почтового сервера в docker контейнере.
## Развернутый сервер:
[mail.harmoning.me](https://mail.harmoning.me)
[mail.harmoning.me](https://mail.harmoning.me/admin)
Логин: admin
Пароль PASSWORD

## Шаги для развертки
1. Необходимо найти веб сервер с необходимым колличеством памяти
2. Зарегистрировать домен и привязать его к нужному серверу
3. Сконфигурировать файл docker-compose в соответсвии с примером. Для этого нужно знать внешний ip адресс сервера, а также его доменное имя
4. Также сконфигурировать mailu.env файл в соответствии с пунктом 3
5. Настроит A и MX доменные записи для того чтобы приходила почта.
6. Чтобы гугл и яндекс не ругались на отсутствие шифрования - сгенерировать его в admin панели, и прописать нужные dns записи.
7. По желанию можно настроить google postmaster для отслеживания спама.
