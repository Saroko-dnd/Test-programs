
window.onload = TestOfTrueOrFalse;

function TestOfTrueOrFalse()
{
    var ResultString = "";
    var UndefinedVariable;
    if (!ResultString)
    {
        ResultString += "1) Empty string is equal to FALSE.<br>";
    }
    if (!UndefinedVariable) {
        ResultString += "2) Undefined variable is equal to FALSE.<br>";
    }
    document.getElementById("PFoResults").innerHTML = ResultString;
}