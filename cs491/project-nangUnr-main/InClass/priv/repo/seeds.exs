# Script for populating the database. You can run it as:
#
#     mix run priv/repo/seeds.exs
#
# Inside the script, you can read and write to any of your
# repositories directly:
#
#     InClass.Repo.insert!(%InClass.SomeSchema{})
#
# We recommend using the bang functions (`insert!`, `update!`
# and so on) as they will fail if something goes wrong.

alias InClass.Company.Area
alias InClass.Company.Generalarea
alias InClass.Company.Status

alias InClass.Repo

area = %Area{name: "UI"}
Repo.insert(area)
area = %Area{name: "Backend"}
Repo.insert(area)
generalarea = %Generalarea{name: "Frontend"}
Repo.insert(generalarea)
generalarea = %Generalarea{name: "Data Management"}
Repo.insert(generalarea)
status = %Status{name: "Complete"}
Repo.insert(status)
status = %Status{name: "Incomplete"}
Repo.insert(status)
