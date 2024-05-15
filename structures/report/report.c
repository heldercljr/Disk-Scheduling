#include "report.h"

Report* create_report(uint amount) {

	Report* report = (Report*) malloc(sizeof(Report));

	report->logs = (Log*) malloc(amount * sizeof(Log));
	report->amount = amount;

	return report;
}
