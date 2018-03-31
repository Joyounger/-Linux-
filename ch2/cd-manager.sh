#!/bin/sh


menu_choice=""
current_cd=""
title_file=""
tracks_file=""
temp_file=""
trap 'rm -f $temp_file' EXIT

get_return() {
	echo -e "press return \c"
	read x
	return 0
}

get_confirm() {
	echo -e "are you sure? c"
	while true;
	do
		read x
		case "$x" in
			y | yse | Y | Yes | YES )
				return 0
				;;
			n | no | N | No | NO
				echo
				echo "cancelled"
				return 1
				;;
			* )
				echo "please enter yes or no"
				;;
		esac
	done
}

get_menu_choice() {
	clear
	echo "Options :-"
	echo 
	echo " a) Add new CD"
	echo " f) Find CD"
	echo " c) count the CDs and tracks in the catalog"
	if [ "$cacatnum" != "" ];
	then
		echo " l) list tracks on $cdtitle"
		echo " r) remove $cdtitle"
		echo " u) update track information for $cdtitle"
	fi
	echo " q) quit"
	echo 
	echo -e "please enter choice then press return \c"
	read menu_choice
	return
}

insert_title() {
	echo $* >> $title_file
	return
}
insert_track() {
	echo $* >> $tracks_file
	return
}

add_record_tracks() {
	echo "enter track information for this CD"
	echo "when no more tracks enter q"
	cdtrack=1
	cdtitle=""
	while [ "$cdtitle" != "q" ]
	do
		echo -e "track $cdtrack,track title? \c"
		read tmp
		cdtitle=${tmp%%,*}
		if [ "$tmp" != "$cdtitle" ]; then
			echo "sorry, no commas allowed"
			continue
		fi
		if [ -n "$cdtitle" ]; then
			if [ "$cdtitle" != "q" ]; then
				insert_track $cacatnum,$cdtrack,$cdtitle
			fi
		else
			cdtrack=$((cdtrack-1))
		fi
		cdtrack=$((cdtrack+1))
	done
}

add_records() {
	# Prompt for the initial information

	echo -e "Enter catalog name \c"
	read tmp
	cdcatnum=${tmp%%,*}

	echo -e "enter title \c"
	read tmp
	cdtitle=${tmp%%,*}

	echo -e "enter type \c"
	read tmp
	cdtype=${tmp%%,*}

	echo -e "enter artist/composer \c"
	read tmp
	cdac=${tmp%%,*}

	# check that they want to enter the information 
	echo about to add new entry
	echo "$cdcatnum $cdtitle $cdtype $cdac"

	# if confirmed then append it to be the titles file

	if get_confirm ; then
		insert_track $cdcatnum,$cdtitle,$cdtype,$cdac
		add_record_tracks
	else
		remove_records
	fi

	return 
}

find_cd() {
	if [ "$1" = "n" ]; then
		asklist=n
	else
		asklist=y
	fi
}


cdcatnum=""
echo -e "enter a string to search for in the CD titles \c"







