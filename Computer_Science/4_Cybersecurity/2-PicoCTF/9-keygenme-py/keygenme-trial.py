#============================================================================#
#============================ARCANE CALCULATOR===============================#
#============================================================================#

import hashlib
from cryptography.fernet import Fernet
import base64
import sys


# GLOBALS --v
arcane_loop_trial = True
jump_into_full = False
full_version_code = ""

username_trial = "MORTON"
bUsername_trial = b"MORTON"

key_part_static1_trial = "picoCTF{1n_7h3_|<3y_of_"
key_part_dynamic1_trial = "xxxxxxxx"
key_part_static2_trial = "}"
key_full_template_trial = key_part_static1_trial + key_part_dynamic1_trial + key_part_static2_trial

star_db_trial = {
  "Alpha Centauri": 4.38,
  "Barnard's Star": 5.95,
  "Luhman 16": 6.57,
  "WISE 0855-0714": 7.17,
  "Wolf 359": 7.78,
  "Lalande 21185": 8.29,
  "UV Ceti": 8.58,
  "Sirius": 8.59,
  "Ross 154": 9.69,
  "Yin Sector CL-Y d127": 9.86,
  "Duamta": 9.88,
  "Ross 248": 10.37,
  "WISE 1506+7027": 10.52,
  "Epsilon Eridani": 10.52,
  "Lacaille 9352": 10.69,
  "Ross 128": 10.94,
  "EZ Aquarii": 11.10,
  "61 Cygni": 11.37,
  "Procyon": 11.41,
  "Struve 2398": 11.64,
  "Groombridge 34": 11.73,
  "Epsilon Indi": 11.80,
  "SPF-LF 1": 11.82,
  "Tau Ceti": 11.94,
  "YZ Ceti": 12.07,
  "WISE 0350-5658": 12.09,
  "Luyten's Star": 12.39,
  "Teegarden's Star": 12.43,
  "Kapteyn's Star": 12.76,
  "Talta": 12.83,
  "Lacaille 8760": 12.88
}


def intro_trial():
    print("\n===============================================\n\
Welcome to the Arcane Calculator, " + username_trial + "!\n")    
    print("This is the trial version of Arcane Calculator.")
    print("The full version may be purchased in person near\n\
the galactic center of the Milky Way galaxy. \n\
Available while supplies last!\n\
=====================================================\n\n")


def menu_trial():
    print("___Arcane Calculator___\n\n\
Menu:\n\
(a) Estimate Astral Projection Mana Burn\n\
(b) [LOCKED] Estimate Astral Slingshot Approach Vector\n\
(c) Enter License Key\n\
(d) Exit Arcane Calculator")

    choice = input("What would you like to do, "+ username_trial +" (a/b/c/d)? ")
    
    if not validate_choice(choice):
        print("\n\nInvalid choice!\n\n")
        return
    
    if choice == "a":
        estimate_burn()
    elif choice == "b":
        locked_estimate_vector()
    elif choice == "c":
        enter_license()
    elif choice == "d":
        global arcane_loop_trial
        arcane_loop_trial = False
        print("Bye!")
    else:
        print("That choice is not valid. Please enter a single, valid \
lowercase letter choice (a/b/c/d).")


def validate_choice(menu_choice):
    if menu_choice == "a" or \
       menu_choice == "b" or \
       menu_choice == "c" or \
       menu_choice == "d":
        return True
    else:
        return False


def estimate_burn():
  print("\n\nSOL is detected as your nearest star.")
  target_system = input("To which system do you want to travel? ")

  if target_system in star_db_trial:
      ly = star_db_trial[target_system]
      mana_cost_low = ly**2
      mana_cost_high = ly**3
      print("\n"+ target_system +" will cost between "+ str(mana_cost_low) \
+" and "+ str(mana_cost_high) +" stone(s) to project to\n\n")
  else:
      # TODO : could add option to list known stars
      print("\nStar not found.\n\n")


def locked_estimate_vector():
    print("\n\nYou must buy the full version of this software to use this \
feature!\n\n")


def enter_license():
    user_key = input("\nEnter your license key: ")
    user_key = user_key.strip()

    global bUsername_trial
    
    if check_key(user_key, bUsername_trial):
        decrypt_full_version(user_key)
    else:
        print("\nKey is NOT VALID. Check your data entry.\n\n")


def check_key(key, username_trial):

    global key_full_template_trial
    print("HELLO: ", key_full_template_trial)

    if len(key) != len(key_full_template_trial):
        return False
    else:
        # Check static base key part --v
        i = 0
        for c in key_part_static1_trial:
            if key[i] != c:
                return False

            i += 1

        # TODO : test performance on toolbox container
        # Check dynamic part --v
        if key[i] != hashlib.sha256(username_trial).hexdigest()[4]:
            return False
        else:
            i += 1

        if key[i] != hashlib.sha256(username_trial).hexdigest()[5]:
            return False
        else:
            i += 1

        if key[i] != hashlib.sha256(username_trial).hexdigest()[3]:
            return False
        else:
            i += 1

        if key[i] != hashlib.sha256(username_trial).hexdigest()[6]:
            return False
        else:
            i += 1

        if key[i] != hashlib.sha256(username_trial).hexdigest()[2]:
            return False
        else:
            i += 1

        if key[i] != hashlib.sha256(username_trial).hexdigest()[7]:
            return False
        else:
            i += 1

        if key[i] != hashlib.sha256(username_trial).hexdigest()[1]:
            return False
        else:
            i += 1

        if key[i] != hashlib.sha256(username_trial).hexdigest()[8]:
            return False



        return True


def decrypt_full_version(key_str):

    key_base64 = base64.b64encode(key_str.encode())
    f = Fernet(key_base64)

    try:
        with open("keygenme.py", "w") as fout:
          global full_version
          global full_version_code
          full_version_code = f.decrypt(full_version)
          fout.write(full_version_code.decode())
          global arcane_loop_trial
          arcane_loop_trial = False
          global jump_into_full
          jump_into_full = True
          print("\nFull version written to 'keygenme.py'.\n\n"+ \
                 "Exiting trial version...")
    except FileExistsError:
    	sys.stderr.write("Full version of keygenme NOT written to disk, "+ \
	                  "ERROR: 'keygenme.py' file already exists.\n\n"+ \
			  "ADVICE: If this existing file is not valid, "+ \
			  "you may try deleting it and entering the "+ \
			  "license key again. Good luck")

def ui_flow():
    intro_trial()
    while arcane_loop_trial:
        menu_trial()



# Encrypted blob of full version
full_version = \
b"""
gAAAAABgT_nv3JrW2AMPOanzoOatT8tWrZSH9V2-H_-sY8RFTh1Vr9guvCw3iIUq7eVs4IhR2u6bI_HkJm6u5VK99vYIKXfthUYjQRMNmo6uMwqdK8ZYm3wH3Z2BlFNmGxMSXKmFhDQujSexuuMg5ZFIb5VhyZeUY4R9KubbghdUIlZ2hBeCpxef_ioNjM7VUKJEyJgxiAtPdMKSgT8y-FJsikUsw9Scbe8nH-bC856u_mqk6AKQnORLmxfsJykFMFm-wOh-unFnUvg9HiT6lYXCrFnXNEFEnq5djwM9H4iRXYwyO4XdHEqVcodEyE3HoPFOh24R9ATElafkxty16jECSabI7k608v6sk2Pxd-EAI0XEtjlVE5Qz-qdnoTIXEXXbwK8Bpw33JwRGJs-WduRmF2G5qVVAGONjaAc9CPXhawUkf2_sNMlnq6lqn7sBb2K7BiqW2Efc88pzfsOYvGQC94CBBhIUQTePRcZ_bUbsDLR8PrWlNQ28Vt6P45URpPDtxkUGQtixiQi9QlPThCFJs28XmApvRQQfJHdje45t2ELeVgn5YMi_FHQ98qgMudwXHXprigHAMmcB2rFPWWhAQn4sIrdL2In424RWO0qOhd9IJrU7DldcrmOMyvpHV87HzVgsRnI97Hn-jiVi_FemDWAsDGFwjaGbrxWUfr01ienDjlrXc-NC2x1Tt6jTHiFb2LbUqzGyjJ-m-5eCuqr1zh8_oCypnBB79XuKMGlngql0NQVEReZ9pDZd3Iax0TJVM55luvuCpjolarAJXz28Ynt5et1DHfnAQ1gQ4laW3ZtRL6TTp1vRpfllOURLpAxNrY03a7cMS5iIS7nXMgllh-uV9S1O3Ww4z_nPSh3q-1yKUilHfuXwdazGjBvfvwDSD3ZgvzgDmvQ-eCNV4I-oEHlAjqAiuwMvClU3Pr-mmBg257A8LHQlJJ7Rl6oYpW-B43esP6sQ2G66ofHbx4ZyUhqH5WC6jjoSuxyRFs6Z6wiNDztgkSdqbSc7iTxtF8oHBqPI_boBwr7YskpWmgwNFhWPzxGwyhMI2H38WGx1klLhNKsa4Ep9vcTuj_ltCL_QZkIgfgklf3QYGWBNLjIPBPkv1c0GqYMPkhnc4Libqdr8LXZJug2ry1s-H16d2U7_cjo9d8usNG2nNhUQvJ8d5I58r3IlioEUWjkUfWy4t3Aw8UN43iZ62MyzE7yzNIYMIwIxgB9qXmrFkh3pFnoZKlPHh7rjVBlbsIgPl64Ewi70P2AdkuDe7BXQ6kX4rdWm3i18ePWIX8n0WYz4eyGz41eRXU2hjyJeIz4Wi0rcjx39LS9BXWq4qHYnT3WNGzONy1ArEiNNiXYk61CyJiaCmFX2BZ5NL85O0ePD-bf7cn7KIWvTGqUoXIP-j1FAYvJy47myTITkurZ7YwEHIAk2sejWMltN-JeI6Jqu8nFKTl1h1sbNpCvAnJmSFczKN9fTJONndpK_PpPbUIilA1UHeqtsQfhNpyx1KK6xeFYyCa0V2sLDnHIHWREXMgcB99TUYSV0_DpbIvwQIaINt7cTDQWWvD7tyFXWltw7VqGAUCgtWYAOIoXj9ZxyOCwuIBHXGD8h8r_kBWx8GlN2Mn70ALuVpPWfR_Y55SHGy3KEUtgig92ms5758hdTQjbvb9wk9byAXvAwpltWQG86XlCIIZSM2vpDqpQ6l-8j_BBir_oXjjuaHQKEw3A3ISpLTP9ZKqcRuDAyeiNNNO_HuPK8hxNFzy7Zvu46tH3waLaPW_v_OivUOx7rP8YxocSv6ON_lwR4sRj3mvAk_WPbXpGQaRaNL813pp5aPzOkUAuod25H6esLw0Io7nCirZ3ZhPKfhtY0bakpTl2o5JJGe_2eEm_D6afBnhnkpEaJOsJhkPj7BXBZH9VJJlBWsHOV8WM3sgy1dBQjCP4C0ThSBhEUwq1mPIFKsvffKJgianCnk0fdmpFOLDJci9i5LDAB-sra6RM4y-HhV2gt3PSvyB_H0WDcdQhSZHVz6U_yNMucIW8-4YwdRwec6HGrNneiyIlacHlKO15PCwWBogndUApfLYrxKHHbxIU1sDybMlIEgBBu9_3gOStqXZu4zBDR93P-qYGz-0jrEHq3YVN9olBLx9yoOVI2AZ9m0PJwpKHYc2uZsciFy__dckefZ79zycUzeSKuKbhaZozQOvdLKwmtcB8y5n3_nwwN6-FQu9APoLqsZoaq3wT5QM6ax-_FS9XwzhqEunognjINxAXu660db73L710noV3CBT76aDY3hiV7fnYhQTfysI4SHQtnAzHXMbxYmNfbMnOALTAkQt7Yaiy_NGAr7jmNOAQwhHIW8eaOsCfhRPl7XjdM7pX2N4EM5cFAEphKWQ62f_3RhnyvaTDNmDXkde-_2FjfBMGirouVJL2rSA-icdD1pfkCKO7U0An5V7AUKuYDTZXTXE4DFWUIq4K36jFmHJ9fwllHoe1_A22RuP4DHm4o7TYEJIeo5UvaVc9Lfd6edWIn8KqDzhTz6TZLWlSbK_RnZlpCv3rdibpHzE-epOv1y5pDv08R8jWnVzHv0c3DgfJzWknRd-S5hIIOd5FEyCAx4NpOqYJjpD109ijZLzDMxuvml8QJmX2tplAp-5xGGiVAFPLse1Vo95f5Wsh8KXwnbNjFQSYf8AgskPp_2spP7rBpVvDrn6HJp7TvQY6mNZMXgLOWy8WHynKESedYkD7iQSHwZ5iMvJTVLDHjYbll0PZyI-Tsy7Q9ZP4ysdzkL5TwGwHa53UhUsiLQmhpkht4dKg3kqq-pA-f5PwKOWKCsKwtUyGFvz9gL7yDNNQwNpSaN2vBy5U8ulVA8SooM9SwmelNHOKvF2rmy6nOQ8mzt-vnnKqCTnc_4VgNakpw86IQVsw7VGQEGTNLD8ULL8bFkSlfICvDQKSLOPONExox17G4YuXFRpDCGoK3KLbM4oKQCi9QWPOL0jhovl0zu1j-XIY7IA2SX4C_Ie9MV27amQi7mwFHYpj3081isJOZd_cUxszijjqOFI71IBeHwSHj5wOnWRUHVLk-aOCT_rKKpae6mPyL0uJsIS1s0B62scEcn0wFa90pjuARSPhc35VCA9TFDcq6W0tAi4aNNzT-vgv4NkqfR6hh_jqs0irQZj7jtUh4OGbkaZljMovt7UYBKd9L4m5gmh1w672_Oif5pDU3YXMdc4FSp39f1wWDvHz0Uw7grUTlvLL3ge6f-Elxe2c0n56nWxs4qo4rqGY9c5BuIFxly_6iymzec33Yo8r0_L5VIRIoWl6lcZq-uIRdTl8mzbVDEoU7r1P6mvg3xUfKfF-Q-XnlfV23XNLSuIF3JF78DkjkNxdOP9dM4dCHbexa5yKeNqAan6Rq7LCnlxTGqP_lxpJO4GvU6npINZ1qjp9ydUveK-Ya7o6rfJqN1GbITvUdaMOFq00OfOsKdZXn7gB_I6el_O-YKJcx3W2X_im81FwT_8P-zW_jEdO-lmztiEyVEvUOFJJfAm-K_G4-HEYzROMPrgof708fnnxDaWGiUi0AtJeEk4sHvf2PTiE0517FcKadlELd_4R-eLKk9Wwu24faJ_R0Ej8NinIbeqCUTb0LkIKa5ChJbL4nXs9f019rUFewPDJhpVLy4nJywzVou9_7-DCMxUT3ld1PjfumXvAbYejzN4Ubue-yfBwPFe_U2YoLM-CyCPNXCbP8WKzCzzNwCcLf8OcQ6gbsyhi0Ul9urHnqWK93qVmPZLEVG9QBEmKPtN6FNWtNIomFiLnl6C9dwbSCWxUJWU_dP7tmVzundLgQhiZhgQz2T7ffSf1aNGSR5hklFayb-MyfOJm46EPx1hVVgqIcdxg7Ko4gt6rpjwAYRQ==
"""





# Enter main loop
ui_flow()

if jump_into_full:
    exec(full_version_code)
