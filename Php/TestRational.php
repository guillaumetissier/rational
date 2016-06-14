<?php
$rational1 = new Rational(1, 2);
$rational2 = new Rational(3, 2);
$rational1->print();
$rational2->print();

$rational1->add(new Rational(3, 4));
echo $rational1 . PHP_EOL;

$rational1->sub(new Rational(8, 3));
echo $rational1 . PHP_EOL;

$rational1->mul(new Rational(13, 17));
echo $rational1 . PHP_EOL;

$rational1->div(new Rational(-3, 14));
echo $rational1 . PHP_EOL;

$rational1->add(new Rational(3, 4))->sub(new Rational(10, 2));
echo $rational1 . PHP_EOL;

if ($rational1 < $rational2) {
	echo "$rational1 < $rational2" . PHP_EOL;
} else {
	echo "$rational1 >= $rational2" . PHP_EOL;
}
