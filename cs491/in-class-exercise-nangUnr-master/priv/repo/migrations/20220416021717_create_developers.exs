defmodule InClass.Repo.Migrations.CreateDevelopers do
  use Ecto.Migration

  def change do
    create table(:developers) do
      add :first_name, :string
      add :last_name, :string
      add :email, :string
      add :area_id, references(:areas, on_delete: :nothing)

      timestamps()
    end

    create index(:developers, [:area_id])
  end
end
