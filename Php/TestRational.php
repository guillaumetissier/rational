<?php
// test print
$rational1 = new Rational(1, 2);
$rational1->print();

// test addition of rationals and cast to string
$rational2 = new Rational(3, 4);
echo "{$rational1} + {$rational2} = ";
$rational1->add($rational2);
echo $rational1 . PHP_EOL;

// test substraction and affectation
$rational3 = new Rational(8, 3);
$rational2 = $rational3;
echo "{$rational1} - {$rational2} = ";
$rational1->sub($rational2);
echo $rational1 . PHP_EOL;

// test multiplication, division and chaining
$rational2 = new Rational(13, 15);
$rational3 = new Rational(3, 5);
echo "{$rational1} x {$rational2} / $rational3 = ";
$rational1->mul($rational2)->div($rational3);
echo $rational1 . PHP_EOL;

// test comparison
if ($rational1 < $rational2) {
	echo "$rational1 < $rational2" . PHP_EOL;
} else {
	echo "$rational1 >= $rational2" . PHP_EOL;
}

// test exception
try {
	$rational1 = new Rational(3, 0);
} catch (Exception $e) {
	echo $e->getMessage() . PHP_EOL;
}
