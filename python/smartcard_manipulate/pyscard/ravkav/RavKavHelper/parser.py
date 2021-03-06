#! /usr/bin/python
COUNTRY_NUM_CODES = dict(
[
("4","Afghanistan"),
("8","Albani"),
("10","Antarctica"),
("12","Algeria"),
("16","American Samoa"),
("20","Andorra"),
("24","Angola"),
("28","Antigua and Barbuda"),
("31","Azerbaijan"),
("32","Argentina"),
("36","Australia"),
("40","Austria"),
("44","Bahamas"),
("48","Bahrain"),
("50","Bangladesh"),
("51","Armenia"),
("52","Barbados"),
("56","Belgium"),
("60","Bermuda"),
("64","Bhutan"),
("68","Bolivia"),
("70","Bosnia and Herzegovina"),
("72","Botswana"),
("74","Bouvet Island"),
("76","Brazil"),
("84","Belize"),
("86","British Indian Ocean Territory"),
("90","Solomon Islands"),
("92","British Virgin Islands"),
("96","Brunei Darussalam"),
("100","Bulgaria"),
("104","Myanmar"),
("108","Burundi"),
("112","Belarus"),
("116","Cambodia"),
("120","Cameroon"),
("124","Canada"),
("132","Cape Verde"),
("136","Cayman Islands"),
("140","Central African Republic"),
("144","Sri Lanka"),
("148","Chad"),
("152","Chile"),
("156","China"),
("158","Taiwan"),
("162","Christmas Island"),
("166","Cocos (Keeling) Islands"),
("170","Colombia"),
("174","Comoros"),
("175","Mayotte"),
("178","Congo PR"),
("180","Congo DR"),
("184","Cook Islands"),
("188","Costa Rica"),
("191","Croatia"),
("192","Cuba"),
("196","Cyprus"),
("203","Czech Republic"),
("204","Benin"),
("208","Denmark"),
("212","Dominica"),
("214","Dominican Republic"),
("218","Ecuador"),
("222","El Salvador"),
("226","Equatorial Guinea"),
("231","Ethiopia"),
("232","Eritrea"),
("233","Estonia"),
("234","Faeroe Islands"),
("238","Falkland Islands (Malvinas)"),
("239","South Georgia and the South Sandwich Islands"),
("242","Fiji"),
("246","Finland"),
("250","France"),
("254","French Guiana"),
("258","French Polynesia"),
("260","French Southern Territories"),
("262","Djibouti"),
("266","Gabon"),
("268","Georgia"),
("270","Gambia"),
("275","Palestinia"),
("276","Germany"),
("288","Ghana"),
("292","Gibraltar"),
("296","Kiribati"),
("300","Greece"),
("304","Greenland"),
("308","Grenada"),
("312","Guadaloupe"),
("316","Guam"),
("320","Guatemala"),
("324","Guinea"),
("328","Guyana"),
("332","Haiti"),
("334","Heard and McDonald Islands"),
("336","Vatican"),
("340","Honduras"),
("344","Hong Kong"),
("348","Hungary"),
("352","Iceland"),
("356","India"),
("360","Indonesia"),
("364","Iran"),
("368","Iraq"),
("372","Ireland"),
("376","Israel"),
("380","Italy"),
("384","Cote D'Ivoire"),
("388","Jamaica"),
("392","Japan"),
("398","Kazakhstan"),
("400","Jordan"),
("404","Kenya"),
("408","North Korea"),
("410","South Korea"),
("414","Kuwait"),
("417","Kyrgyz Republic"),
("418","Laos"),
("422","Lebanon"),
("426","Lesotho"),
("428","Latvia"),
("430","Liberia"),
("434","Libya"),
("438","Liechtenstein"),
("440","Lithuania"),
("442","Luxembourg"),
("446","Macao"),
("450","Madagascar"),
("454","Malawi"),
("458","Malaysia"),
("462","Maldives"),
("466","Mali"),
("470","Malta"),
("474","Martinique"),
("478","Mauritania"),
("480","Mauritius"),
("484","Mexico"),
("492","Monaco"),
("496","Mongolia"),
("498","Moldova"),
("500","Montserrat"),
("504","Morocco"),
("508","Mozambique"),
("512","Oman"),
("516","Namibia"),
("520","Nauru"),
("524","Nepal"),
("528","Netherlands"),
("530","Netherlands Antilles"),
("533","Aruba"),
("540","New Caledonia"),
("548","Vanuatu"),
("554","New Zealand"),
("558","Nicaragua"),
("562","Niger"),
("566","Nigeria"),
("570","Niue"),
("574","Norfolk Island"),
("578","Norway"),
("580","Northern Mariana Islands"),
("581","United States Minor Outlying Islands"),
("583","Micronesia"),
("584","Marshall Islands"),
("585","Palau"),
("586","Pakistan"),
("591","Panama"),
("598","Papua New Guinea"),
("600","Paraguay"),
("604","Peru"),
("608","Philippines"),
("612","Pitcairn Island"),
("616","Poland"),
("620","Portugal"),
("624","Guinea-Bissau"),
("626","Timor-Leste"),
("630","Puerto Rico"),
("634","Qatar"),
("638","Reunion"),
("642","Romania"),
("643","Russia"),
("646","Rwanda"),
("654","St. Helena"),
("659","St. Kitts and Nevis"),
("660","Anguilla"),
("662","St. Lucia"),
("666","St. Pierre and Miquelon"),
("670","St. Vincent and the Grenadines"),
("674","San Marino"),
("678","Sao Tome and Principe"),
("682","Saudi Arabia"),
("686","Senegal"),
("690","Seychelles"),
("694","Sierra Leone"),
("702","Singapore"),
("703","Slovakia"),
("704","Viet Nam"),
("705","Slovenia"),
("706","Somalia"),
("710","South Africa"),
("716","Zimbabwe"),
("724","Spain"),
("732","Western Sahara"),
("736","Sudan"),
("740","Suriname"),
("744","Svalbard & Jan Mayen Islands"),
("748","Swaziland"),
("752","Sweden"),
("756","Switzerland"),
("760","Syria"),
("762","Tajikistan"),
("764","Thailand"),
("768","Togo"),
("772","Tokelau"),
("776","Tonga"),
("780","Trinidad and Tobago"),
("784","United Arab Emirates"),
("788","Tunisia"),
("792","Turkey"),
("795","Turkmenistan"),
("796","Turks and Caicos Islands"),
("798","Tuvalu"),
("800","Uganda"),
("804","Ukraine"),
("807","Macedonia"),
("818","Egypt"),
("826","United Kingdom"),
("834","Tanzania"),
("840","United States of America"),
("850","US Virgin Islands"),
("854","Burkina Faso"),
("858","Uruguay"),
("860","Uzbekistan"),
("862","Venezuela"),
("876","Wallis and Futuna Islands"),
("882","Samoa"),
("887","Yemen"),
("891","Serbia and Montenegro"),
("894","Zambia")
]
)

RAVKAV_ISSUERS = dict(
[
("0","undefined"),
("1","Service Center (Postal Bank)"),
("2","Israel Railways"),
("3","Egged"),
("4","Egged Transport"),
("5","Dan"),
("6","NTT (United Bus Services Nazareth)"),
("7","NTT (Nazareth Travel & Tourism)"),
("8","GB Tours"),
("9","Omni Nazrin Express (transferred to Nativ Express)"),
("10","Eilot Regional Council"),
("11","Illit (merged with Kavim)"),
("12","undefined 12"),
("13","undefined 13"),
("14","Nativ Express"),
("15","Metropoline"),
("16","Superbus"),
("17","Connex Veolia (transferred to Afikim)"),
("18","Kavim"),
("19","Metrodan (defunct, transferred to Dan Be\'er Sheva)"),
("20","Carmelit"),
("21","CityPass"),
("22","Tel Aviv Light Rail operator"),
("23","Galim (Narkis Gal)"),
("24","Golan Regional Council"),
("25","Afikim"),
("26","undefined 26"),
("27","undefined 27"),
("28","undefined 28"),
("29","undefined 29"),
("30","Dan North"),
("31","Dan South"),
("32","Dan Be\'er Sheva"),
("33","undefined 33"),
("34","undefined 34"),
("35","undefined 35"),
("36","undefined 36"),
("37","undefined 37"),
("38","undefined 38"),
("39","undefined 39"),
("40","undefined 40"),
("41","East Jerusalem operators"),
("42","Jerusalem - Ramallah united"),
("43","(obsolete) Jerusalem - Mahane Shuafat"),
("44","Jerusalem - Anata united"),
("45","Jerusalem - Isawiya united"),
("46","(obsolete) Jabal Al Muhbar Ltd"),
("47","Jerusalem - Mount of Olives"),
("48","(obsolete) Abu-Tor Siluan bus company"),
("49","Jerusalem - Isawiya - Mahane Shuafat united"),
("50","South Jerusalem united"),
("51","Jerusalem - Sur Baher united"),
("52","(obsolete) Ras-al Amud Izriya - Abu-Dis"),
("53","(obsolete) Jerusalem - A. Swahra united"),
("98","Tel Aviv Service Taxi Lines 4, 2 and 5"),
("240","(Technical, Service Center - Contract restores"),
("250","Israel Defence Forces")
])

RAVKAV_PROFILES = dict(
[
 ("0", "Standard"),
 ("1" , "Adult"),
 ("2" , "Child"),
 ("3" , "Extended Student"),
 ("4" , "Senior Citizen"),
 ("5" , "Handicapped"),
 ("6" , "Poor vision / Blind"),
 ("7" , "Deaf / Dumb"),
 ("8" , "Unemployed"),
 ("9" , "Personal"),
 ("10" , "Israel Defence Forces / Ministry of Defence / Security personnel"),
 ("11" , "Resident"),
 ("12" , "Transport"),
 ("13" , "Public Transport Employee"),
 ("14" , "Long-term transport"),
 ("15" , "Local transport"),
 ("16" , "Commuter"),
 ("17" , "Animal"),
 ("18" , "Object"),
 ("19" , "Standard Student"),
 ("20" , "20"),
 ("21" , "21"),
 ("22" , "22"),
 ("23" , "23"),
 ("24" , "24"),
 ("25" , "25"),
 ("26" , "26"),
 ("27" , "27"),
 ("28" , "28"),
 ("29" , "29"),
 ("30" , "30"),
 ("31" , "31"),
 ("32" , "Child aged 5-10"),
 ("33" , "Youth aged 5-18"),
 ("34" , "National Service"),
 ("35" , "Service without pay (SHALAT) / Pre-Army Course (KADATS)"),
 ("36" , "Israel Police"),
 ("37" , "Prison Services"),
 ("38" , "Member of Parliament"),
 ("39" , "Parliament Guard"),
 ("40" , "Eligible for Social Security"),
 ("41" , "Victim of Hostilities"),
 ("42" , "New Immigrant in Rural Settlement"),
 ("43" , "Person Accompanying Poor vision / Blind"),
 ("44" , "44"),
 ("45" , "45"),
 ("46" , "46"),
 ("47" , "47"),
 ("48" , "48"),
 ("49" , "49"),
 ("50" , "50"),
 ("51" , "51"),
 ("52" , "52"),
 ("53" , "Residents of the South (Israel Railways"),
 ("54" , "Residents of the Valley (Israel Railways"),
 ("55" , "Residents of Ahihud (Israel Railways"),
 ("56" , "56"),
 ("57" , "57"),
 ("58" , "58"),
 ("59" , "Youth Student on Intercity Ride")
])

RAVKAV_LINE_TYPES = dict(
[
     ("0","Not set or generic public transport"),
     ("1","Urban"),
     ("2","Regional"),
     ("3","Intercity"),
     ("4","Light Rail"),
     ("5","Intercity Rail"),
     ("15","Transport method")
]
)

RAVKAV_EVENT_TYPES = dict(
[
    ("0","Action -"),
    ("1","Entry -"), 
    ("2","Exit -"),
    ("3","Transit -"),
    ("4","Prevalidate -"),
    ("5","Inspection -"),
    ("6","Transit trip"),
    ("7","Exit from station -"),
    ("8","Other usage -"),
    ("9","Contract cancel -"),
    ("12","Contract load and used immediately for -"),
    ("13","Contract load -"),
    ("14","Personalization / Card issuance"),
    ("15","Card invalidation")
]
)

RAVKAV_RAIL_LOCATIONS = dict(
[
    ("1","[Ticketing Machine] Tel Aviv Center - Savidor"), 
    ("2","[Ticketing Machine] Herzliya"),                  
    ("3","[Ticketing Machine] Beit Yehoshua"),             
    ("4","[Ticketing Machine] Netanya"),                   
    ("5","[Ticketing Machine] Hadera West"),               
    ("6","[Ticketing Machine] Binyamina"),                 
    ("7","[Ticketing Machine] Ceasarea - Pardes Hana"),    
    ("8","[Ticketing Machine] Atlit"),                     
    ("9","[Ticketing Machine] Haifa Bat Galim"),           
    ("10","[Ticketing Machine] Haifa - Hutsot HaMifrats"),       
    ("11","[Ticketing Machine] Kiryat Hayim"),                  
    ("12","[Ticketing Machine] Kiryat Motzkin"),                
    ("13","[Ticketing Machine] Akko"),                           
    ("14","[Ticketing Machine] Haifa Hof HaKarmel (Razi\'el)"),  
    ("15","[Ticketing Machine] Kfar Saba - Nordau (A. Kostyuk)"),
    ("16","[Ticketing Machine] Nahariya"),                       
    ("17","[Ticketing Machine] Jerusalem Biblical Zoo"),         
    ("18","[Ticketing Machine] Beit Shemesh"),                   
    ("19","[Ticketing Machine] Kiryat Gat"),                     
    ("20","[Ticketing Machine] Lod"),                            
    ("21","[Ticketing Machine] Be\'er Sheva North / University"),
    ("22","[Ticketing Machine] Kfar Habbad"),                    
    ("23","[Ticketing Machine] Tel Aviv HaShalom"),              
    ("24","[Ticketing Machine] Haifa East"),                 
    ("25","[Ticketing Machine] Haifa Center HaShmona"),          
    ("26","[Ticketing Machine] Ramla"),                          
    ("27","[Ticketing Machine] Rosh Ha\'Ayin North"),            
    ("28","[Ticketing Machine] Be\'er Ya\'akov"),                
    ("29","[Ticketing Machine] Rehovot E. Hadar"),               
    ("30","[Ticketing Machine] Yavne East"),                     
    ("31","[Ticketing Machine] Rishon Le\'Tziyon - HaRishonim"), 
    ("32","[Ticketing Machine] Ashdod Ad Halom (M. Bar Kochva)"),
    ("33","[Ticketing Machine] Rosh Ha\'Ayin South"),        
    ("34","[Ticketing Machine] Petah-Tikva - Sgula"),            
    ("35","[Ticketing Machine] Bnei Brak"),                      
    ("36","[Ticketing Machine] Tel Aviv - University"),          
    ("37","[Ticketing Machine] Be\'er Sheva Center"),            
    ("38","[Ticketing Machine] Haifa - HaMifrats Central"),      
    ("39","[Ticketing Machine] Tel Aviv HaHagana"),              
    ("40","[Ticketing Machine] Ben Gurion Airport"),             
    ("41","[Ticketing Machine] Jerusalem Malha"),                
    ("42","[Ticketing Machine] Ashkelon"),                       
    ("43","[Ticketing Machine] Dimona"),                         
    ("44","[Ticketing Machine] Hod HaSharon - Sokolov"),         
    ("45","[Ticketing Machine] Petah-Tikva - Kiryat Arye"),      
    ("46","[Ticketing Machine] Lod Ganey Aviv"),                 
    ("47","[Ticketing Machine] Lehavim - Rahat"),                
    ("48","[Ticketing Machine] Modi\'in - Pa\'atei Modi\'in"),  
    ("49","[Ticketing Machine] Modi\'in Center"),               
    ("50","[Ticketing Machine] Holon Junction"),                 
    ("51","[Ticketing Machine] Holon - Wolfson"),                
    ("52","[Ticketing Machine] Bat Yam - Yoseftal"),             
    ("53","[Ticketing Machine] Bat Yam - Komemiyyut"),           
    ("54","[Ticketing Machine] Rishon Le\'Tziyon - Moshe Dayan"),
    ("55","[Ticketing Machine] Yavne West"),                     
    ("56","[Ticketing Machine] Sderot"),                         
    ("57","[Ticketing Machine] Netivot"),                        
    ("58","[Ticketing Machine] Ofakim"),                         
    ("59","[Ticketing Machine] Netanya Sapir"),                  
    ("60","[Ticketing Machine] Yokneam - Kfar Yehoshua"),        
    ("61","[Ticketing Machine] Migdal HaEmek - Kfar Barukh"),    
    ("62","[Ticketing Machine] Afula"),                          
    ("63","[Ticketing Machine] Beit She\'an"),                   
    ("64","[Ticketing Machine] Ahihud"),                         
    ("65","[Ticketing Machine] Carmiel"),                        
    ("66","[Ticketing Machine] Ra\'anana West"),                 
    ("67","[Ticketing Machine] Ra\'anana South"),                
    ("68","[Ticketing Machine] Kiryat Malakhi - Yoav"),          
    ("69","[Ticketing Machine] Jerusalem - Yitshak Navon"),     
    ("70","[Ticketing Machine] Mazkeret Batya"),                 
    ("7001","Tel Aviv Center - Savidor"),                
    ("7002", "Herzliya"),                                 
    ("7003", "Beit Yehoshua"),                            
    ("7004", "Netanya"),                                  
    ("7005", "Hadera West"),                              
    ("7006", "Binyamina"),                                
    ("7007", "Ceasarea - Pardes Hana"),                   
    ("7008", "Atlit"),                                    
    ("7009", "Haifa Bat Galim"),                          
    ("7010", "Haifa - Hutsot HaMifrats"),                 
    ("7011", "Kiryat Hayim"),                            
    ("7012", "Kiryat Motzkin"),                          
    ("7013", "Akko"),                                     
    ("7014", "Haifa Hof HaKarmel (Razi\'el)"),            
    ("7015", "Kfar Saba - Nordau (A. Kostyuk)"),          
    ("7016", "Nahariya"),                                 
    ("7017", "Jerusalem Biblical Zoo"),                   
    ("7018", "Beit Shemesh"),                             
    ("7019", "Kiryat Gat"),                               
    ("7020", "Lod"),                                      
    ("7021", "Be\'er Sheva North / University"),          
    ("7022", "Kfar Habbad"),                              
    ("7023", "Tel Aviv HaShalom"),                        
    ("7024", "Haifa East"),                           
    ("7025", "Haifa Center HaShmona"),                    
    ("7026", "Ramla"),                                    
    ("7027", "Rosh Ha\'Ayin North"),                      
    ("7028", "Be\'er Ya\'akov"),                          
    ("7029", "Rehovot E. Hadar"),                         
    ("7030", "Yavne East"),                               
    ("7031", "Rishon Le\'Tziyon - HaRishonim"),           
    ("7032", "Ashdod Ad Halom (M. Bar Kochva)"),          
    ("7033", "Rosh Ha\'Ayin South"),                  
    ("7034", "Petah-Tikva - Sgula"),                      
    ("7035", "Bnei Brak"),                                
    ("7036", "Tel Aviv - University"),                    
    ("7037", "Be\'er Sheva Center"),                      
    ("7038", "Haifa - HaMifrats Central"),                
    ("7039", "Tel Aviv HaHagana"),                        
    ("7040", "Ben Gurion Airport"),                       
    ("7041", "Jerusalem Malha"),                          
    ("7042", "Ashkelon"),                                 
    ("7043", "Dimona"),                                   
    ("7044", "Hod HaSharon - Sokolov"),                   
    ("7045", "Petah-Tikva - Kiryat Arye"),                
    ("7046", "Lod Ganey Aviv"),                           
    ("7047", "Lehavim - Rahat"),                          
    ("7048", "Modi\'in - Pa\'atei Modi\'in"),            
    ("7049", "Modi\'in Center"),                         
    ("7050", "Holon Junction"),                           
    ("7051", "Holon - Wolfson"),                          
    ("7052", "Bat Yam - Yoseftal"),                       
    ("7053", "Bat Yam - Komemiyyut"),                     
    ("7054", "Rishon Le\'Tziyon - Moshe Dayan"),          
    ("7055", "Yavne West"),                               
    ("7056", "Sderot"),                                   
    ("7057", "Netivot"),                                  
    ("7058", "Ofakim"),                                   
    ("7059", "Netanya Sapir"),                            
    ("7060", "Yokneam - Kfar Yehoshua"),                  
    ("7061", "Migdal HaEmek - Kfar Barukh"),              
    ("7062", "Afula"),                                    
    ("7063", "Beit She\'an"),                             
    ("7064", "Ahihud"),                                   
    ("7065", "Carmiel"),                                  
    ("7066", "Ra\'anana West"),                           
    ("7067", "Ra\'anana South"),                          
    ("7068", "Kiryat Malakhi - Yoav"),                    
    ("7069", "Jerusalem - Yitshak Navon"),               
    ("7070", "Mazkeret Batya"),                            
    ("7071","7071")
])
def parse_country_code(code):
    return(COUNTRY_NUM_CODES[code])
def parse_issuer_code(code):
    return (RAVKAV_ISSUERS[code])
def parse_profile_code(code):
    return (RAVKAV_PROFILES[code])
def parse_line_types_code(code):
    return(RAVKAV_LINE_TYPES[code])
def parse_event_type_code(code):
    return(RAVKAV_EVENT_TYPES[code])
def parse_rail_location_code(code):
    return(RAVKAV_RAIL_LOCATIONS[code])
