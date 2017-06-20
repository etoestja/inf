#1/bin/bash
fn="remove_me"
echo -e "Write text to shred here:\n" > $fn
vim $fn
echo "Shreding..."
shred -u -v $fn
