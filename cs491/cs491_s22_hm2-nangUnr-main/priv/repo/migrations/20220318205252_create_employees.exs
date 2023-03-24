defmodule Cs491Hm2.Repo.Migrations.CreateEmployees do
  use Ecto.Migration

  def change do
    create table(:employees) do
      add :first_name, :string
      add :last_name, :string
      add :role_id, references(:roles, on_delete: :nothing)
      add :department_id, references(:departments, on_delete: :nothing)

      timestamps()
    end

    create index(:employees, [:role_id])
    create index(:employees, [:department_id])
  end
end
