var arrLang = {
	'en': {
		'EBan List Link': 'EBan List',
		'Go Back Link': 'Go Back',
		'Find': 'Find',
		'Steam Wrong': 'SteamID is in the wrong format. Supported formats: STEAM_1:0:123456789 and [U:1:123456789]',
		'Search Results': 'Search Results',
		'Server': 'Server',
		'Player': 'Player',
		'Reason': 'Reason',
		'Admin': 'Admin',
		'Duration': 'Duration',
		'Permanent': 'Permanent',
		'Permanent Removed': 'Permanent(Removed)',
		'Expired': 'Expired',
		'Removed': 'Removed',
		'Week_1': 'Week',
		'Week_2': 'Weeks',
		'Week_3': 'Weeks',
		'Day_1': 'Day',
		'Day_2': 'Days',
		'Day_3': 'Days',
		'Hour_1': 'Hour',
		'Hour_2': 'Hours',
		'Hour_3': 'Hours',
		'Minute_1': 'Minute',
		'Minute_2': 'Minutes',
		'Minute_3': 'Minutes',
		'Issued': 'Issued:',
		'Removed_2': 'Removed:',
		'Unbanned by': 'Unbanned by:',
		'Reason_2': 'Reason:',
		'Never': 'Never'
	},
	'ru': {
		'EBan List Link': 'Список ЕБанов',
		'Go Back Link': 'Назад',
		'Find': 'Найти',
		'Steam Wrong': 'SteamID имеет неверный формат. Поддерживаемые форматы: STEAM_1:0:123456789 и [U:1:123456789]',
		'Search Results': 'Результат поиска',
		'Server': 'Сервер',
		'Player': 'Игрок',
		'Reason': 'Причина',
		'Admin': 'Админ',
		'Duration': 'Длительность',
		'Permanent': 'Навсегда',
		'Permanent Removed': 'Навсегда(Снят)',
		'Expired': 'Истёк',
		'Removed': 'Снят',
		'Week_1': 'Неделя',
		'Week_2': 'Недели',
		'Week_3': 'Недель',
		'Day_1': 'День',
		'Day_2': 'Дня',
		'Day_3': 'Дней',
		'Hour_1': 'Час',
		'Hour_2': 'Часа',
		'Hour_3': 'Часов',
		'Minute_1': 'Минута',
		'Minute_2': 'Минуты',
		'Minute_3': 'Минут',
		'Issued': 'Истекает:',
		'Removed_2': 'Снят:',
		'Unbanned by': 'Разебанен:',
		'Reason_2': 'Причина:',
		'Never': 'Никогда'
	}
};

function SetLang(lang)
{
	$('.lang').each(function(index, element){
		$(this).text(arrLang[lang][$(this).attr('key_phrase')]);
	});
}