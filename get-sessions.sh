if [ -f master2024.txt ]; then
    echo "master2024.txt found! Making a copy..."
	cp master2024.txt session-copies/master2024-"`date +"%d-%m-%Y"`".txt.copy
fi

if [ -f master2024-int.txt ]; then
    echo "master2024-int.txt found! Making a copy..."
	cp master2024-int.txt session-copies/master2024-int-"`date +"%d-%m%Y"`".txt.copy
fi

#curl --location --cookie cookies.txt https://cddis.nasa.gov/archive/vlbi/ivscontrol/master2024.txt > master2024.txt
#curl --location --cookie cookies.txt https://cddis.nasa.gov/archive/vlbi/ivscontrol/master2024-int.txt > master2024-int.txt
curl --location --cookie cookies.txt https://cddis.nasa.gov/archive/vlbi/ivscontrol/master2024.txt > master2024.txt
curl --location --cookie cookies.txt https://cddis.nasa.gov/archive/vlbi/ivscontrol/master2024-int.txt > master2024-int.txt

