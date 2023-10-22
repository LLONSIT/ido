printf 'Checking if ugen is "broken"...\n'
build/ugen -t a.T a.B -o binasm
sha1sum -c binasm.sha1
