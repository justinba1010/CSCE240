#!/usr/bin/env python3
"""Module documentation goes here
"""

import json
import subprocess
import sys

class QuickTest:
    """Class documentation goes here
    """
    def __init__(self):
        self._APP = "./parse_scores"
        self._INPUT = \
            """2 1234 3 98.7 87.92 77.32 2345 3 93.1 90.23 81.21"""

        self.test()


    def test(self):
        """Method documentation goes here
        """
        returncode, out = self.run()

        if 0 != returncode:
            print("ERROR: EXPECTED return 0, ACTUAL return {}."
                    .format(returncode), file=sys.stderr)

        if not out:
            print("ERROR: No output from student app.", file=sys.stderr) 

        print("STUDENT OUTPUT")
        print("------------------------")
        print(out)
        print("------------------------")

        try:
            student_info = json.loads(out)

            if student_info['max_id'] != 1234:
                print(
                    f"ERROR: EXPECTED max_id 1234 ACTUAL : {student_info['max_id']}") 
    
            if student_info['max_score'] != 98.7:
                print(
                    f"ERROR: EXPECTED max_score 98.7 ACTUAL : {student_info['max_score']}")
    
        except json.decoder.JSONDecodeError as err:
            print(f"ERROR: JSON parse error: {err}")


    def run(self):
        """Method documentation goes here.
        """
        with subprocess.Popen(self._APP, stderr=subprocess.PIPE,
                stdin=subprocess.PIPE, stdout=subprocess.PIPE) as proc:
          out, err = proc.communicate(input=self._INPUT.encode("utf-8"))
          
          try:
            return proc.returncode, out.decode("utf-8") if out else None
          except UnicodeDecodeError as e:
            return proc.returncode, "Serious execution badness:" + format(e)



if __name__ == "__main__":
    test = QuickTest()
